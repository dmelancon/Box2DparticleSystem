//
//  box.cpp
//  Box2d
//
//  Created by Dan on 3/8/14.
//
//
#include <Box2D/Box2D.h>
#include "box.h"
#include "cinder/Rand.h"
using namespace ci;


box1::box1(const Vec2f &pos, b2World* world ){
    createMesh();
    mPosition = pos;
    mLife = ci::randInt(100,120);
    mDead = false;
    mWorld= world;
    mNumContacts = 0;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set( mPosition.x, mPosition.y );
    bodyDef.linearVelocity.Set(randFloat(-10.0,10.0),randFloat(-10.0,10.0));
    bodyDef.angularVelocity = randFloat(1.0);
    mBody = mWorld->CreateBody( &bodyDef );
    mBody->SetUserData( this );
    dynamicBox.SetAsBox( 17.5, 17.5);
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.5f; // bounce
    mBody->CreateFixture( &fixtureDef );

//    std::vector<uint32_t> indices;
//    uint32_t i=0;
//    while(i < 4){
//        indices.push_back(i);
//        i++;
//  }
//    
//    gl::VboMesh::Layout layout;
//    layout.setDynamicPositions();
//    layout.setStaticIndices();
//    layout.hasColorsRGB();
    
  

}

//


//box1::~box1(){}
void box1::startContact() { mNumContacts++;

}
void box1::endContact() { //mNumContacts--;
}

void box1::addBox(){}

void box1::update(){
    if (mNumContacts == 3){
        mDead =true;
        mWorld->DestroyBody(mBody);
    }
}


bool box1::isDead(){
    return mDead;
}

void box1::createMesh(){
    Vec3f v0(-17.5,-17.5,0);
    Vec3f v1( -17.5,17.5,0);
    Vec3f v2( 17.5, 17.5,0);
    Vec3f v3(17.5, -17.5,0);
    Color c0(0.3,0,0);
    TriMesh mMesh;
    mMesh.clear();
    mMesh.appendColorRgb(c0);
    mMesh.appendVertex( v0 );
    mMesh.appendColorRgb(c0);
    mMesh.appendVertex(  v1 );
    mMesh.appendColorRgb(c0);
    mMesh.appendVertex( v2 );
    mMesh.appendColorRgb(c0);
    mMesh.appendVertex( v3 );
    int vIdx0 = mMesh.getNumVertices() - 4;
    int vIdx1 = mMesh.getNumVertices() - 3;
    int vIdx2 = mMesh.getNumVertices() - 2;
    int vIdx3 = mMesh.getNumVertices() - 1;
    mMesh.appendTriangle( vIdx0, vIdx1, vIdx2 );
    mMesh.appendTriangle( vIdx0, vIdx2, vIdx3 );
    mesh = gl::VboMesh(mMesh);

}


void box1::drawBox(){
        Vec2f pos = Vec2f(mBody->GetPosition().x,mBody->GetPosition().y);
        glPushMatrix();
        t = toDegrees( mBody->GetAngle() );
        gl::translate(pos);
        gl::rotate( t );
      // gl::draw(mMesh);
    //Rectf rect(-35,-35,35,35);
    //gl::drawSolidRect( rect );
        gl::draw( mesh );
        glPopMatrix();

}
float &box1::getAngle(){
    return t;}
Vec2f  box1::getPosition(){
    return Vec2f(mBody->GetPosition().x,mBody->GetPosition().y);
}

