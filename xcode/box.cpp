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
     glColor3f(0,0,1);
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
    dynamicBox.SetAsBox( 15, 15);
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.5f; // bounce
    mBody->CreateFixture( &fixtureDef );
}

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
void box1::drawBox(){
    if(mNumContacts==0){
        glColor3f(0.3,0,0);}
    if(mNumContacts==1){
        glColor3f(.55,0,0);}
    if(mNumContacts==2){
        glColor3f(1,0,0);}
    fixtureDef.restitution = 1.5f;
        Vec2f pos = Vec2f(mBody->GetPosition().x,mBody->GetPosition().y);
        glPushMatrix();
        t = toDegrees( mBody->GetAngle() );
        gl::translate(pos);
        gl::rotate( t );
        Rectf rect(-15,-15,15,15);
        gl::drawSolidRect( rect );
        glPopMatrix();
    
}
float &box1::getAngle(){
    return t;}
Vec2f  box1::getPosition(){
    return Vec2f(mBody->GetPosition().x,mBody->GetPosition().y);
}

