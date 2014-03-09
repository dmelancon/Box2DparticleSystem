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
    mPosition = pos;
    mLife = ci::randInt(1000,1000);
    mDead = false;
    mWorld= world;
    mNumContacts = 0;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set( mPosition.x, mPosition.y );
    bodyDef.linearVelocity.Set(randFloat(-10.0,10.0),randFloat(-10.0,10.0));
    bodyDef.angularVelocity = randFloat(1.0);
    mBody = mWorld->CreateBody( &bodyDef );
    mBody->SetUserData( this );
    
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox( 15, 15);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.5f; // bounce
    mBody->CreateFixture( &fixtureDef );

    }
void box1::startContact() { mNumContacts++;}
void box1::endContact() { //mNumContacts--;
}

void box1::addBox(){}

void box1::update(){

    if(mLife > 0){
        mLife--;
    }else{
//if ( mNumContacts > 0){
        mLife = 0;
        mDead = true;
        mWorld->DestroyBody(mBody);

    }
}


bool box1::isDead(){
    return mDead;
}
void box1::drawBox(){
    

    
        Vec2f pos = Vec2f(mBody->GetPosition().x,mBody->GetPosition().y);
		glPushMatrix();
    t = toDegrees( mBody->GetAngle() );
		gl::translate(pos);
		gl::rotate( t );
    if ( mNumContacts == 1){
        glColor3f(1,0,0);//red
    }else if (mNumContacts == 2){
        glColor3f(1,0.5f,0);

    }else if(mNumContacts ==3){
        glColor3f(0,1,0);//red

    }
    
    else{
        glColor3f(1,1,1);}
        Rectf rect( -15, -15, 15, 15);
		gl::drawSolidRect( rect );
        glPopMatrix();
}
float & box1::getAngle(){
    return t;}

