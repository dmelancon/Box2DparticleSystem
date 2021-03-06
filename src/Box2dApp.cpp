#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include <Box2D/Box2D.h>
#include "cinder/Rand.h"
#include "box.h"
#include "ground.h"
#include "ContactListener.h"

using namespace ci;
using namespace ci::app;
using namespace std;

float BOX_SIZE = 10;


class Box2dApp : public AppNative {
  public:
	void setup();
    void prepareSettings(Settings*);
	void mouseDrag( MouseEvent event );
	void update();
	void draw();
	b2World				*mWorld;
    ground mGround;
    ContactListener myContactListenerInstance;
	list<box1*> mBoxes;
    list<particleSystem*> ps;
};

void Box2dApp::setup()
{
    b2Vec2 gravity( 0.0f,0.1f );
	mWorld = new b2World( gravity );
    mWorld->SetContactListener(&myContactListenerInstance);
    mGround = ground(mWorld);
    
}
void Box2dApp::prepareSettings(cinder::app::AppBasic::Settings *settings){
    settings->setWindowSize(1200,800);
}

void Box2dApp::mouseDrag( MouseEvent event )
{
    box1* b1 = new box1(Vec2f(randFloat(getWindowWidth()),randFloat(getWindowHeight())),mWorld);
    mBoxes.push_back(b1);
    }

void Box2dApp::update()
{
    for( int i = 0; i < 10; ++i ){
        mWorld->Step( 1 / 30.0f, 10, 10 );
    }
    for( list<box1*>::iterator boxIt = mBoxes.begin(); boxIt != mBoxes.end(); ) {
        if((*boxIt)->isDead()){
        ps.push_back(new particleSystem(200,(*boxIt)->getPosition(), (*boxIt)->getAngle()));
        boxIt = mBoxes.erase(boxIt);
     }else {
        (*boxIt)->update();
        ++boxIt;
     }
    }
    for( list<particleSystem*>::iterator psIt = ps.begin(); psIt != ps.end();) {
        if((*psIt)->isDead() == true){
            psIt = ps.erase(psIt);}
                else{
                    (*psIt)->update();
                    ++psIt;
            }

    }
   
}

void Box2dApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 1, 1, 1 ) );
 //   gl::setMatricesWindow(getWindowWidth(),getWindowHeight());
    for( list<box1*>::iterator boxIt = mBoxes.begin(); boxIt != mBoxes.end(); ++boxIt ) {
        (*boxIt)->drawBox();
	}
    for( list<particleSystem*>::iterator psIt = ps.begin(); psIt != ps.end(); ++psIt ) {
        (*psIt)->draw();
	}
}

CINDER_APP_NATIVE( Box2dApp, RendererGl )
