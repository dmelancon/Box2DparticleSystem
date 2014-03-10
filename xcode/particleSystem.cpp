//
//  particleSystem.cpp
//  Box2d
//
//  Created by Dan on 3/9/14.
//
//

#include "particleSystem.h"
#include "cinder/Rand.h"

particleSystem::particleSystem(){} //dummy constructor

particleSystem::particleSystem( int size, ci::Vec2f mPos, float ang){
    angle = ang;
    mParticles.resize(size);
    for(std::list<Particle>::iterator it = mParticles.begin(); it != mParticles.end(); ++it){

        it->mPosition = ci::Vec2f(mPos.x+ci::randFloat(-7.5f,7.5f), mPos.y+ci::randFloat(-7.5f,7.5f));
        it->mLife = ci::randFloat(5,90);
        it->mVelocity = ci::Vec2f::zero();
       it->mAcceleration = ci::Vec2f(ci::randFloat(-1,1),ci::randFloat(-1.0,1.0f));;
    }
}
particleSystem::~particleSystem(){}
void particleSystem::update(){

    for(std::list<Particle>::iterator it = mParticles.begin(); it != mParticles.end();){
        if(it->mLife <= 0){
          it =  mParticles.erase(it);
        }
        else {
            it->mAcceleration += ci::Vec2f(ci::randFloat(-1.0,1.0),ci::randFloat(-1.0,1.0));
            it->mVelocity += it->mAcceleration;
            it->mPosition += it->mVelocity;
            it->mAcceleration *= 0;
            it->mLife--;
            ++it;
            }
    }
    x+=.05;
}
bool particleSystem::isDead(){
    
    if(mParticles.size()==0){
        return true;
    }else{
        return false;
    }
}

void particleSystem::draw(){
       for(std::list<Particle>::iterator it = mParticles.begin(); it != mParticles.end(); ++it){

            ci::gl::pushMatrices();
            ci::gl::translate(it->mPosition);

            ci::gl::color(1.0,0,0,1);
            ci::Rectf rect( -5+x, -5+x, 5-x, 5-x);
            ci::gl::drawSolidRect( rect );
           ci::gl::rotate(angle);

            ci::gl::popMatrices();
        }
    
}