//
//  box.h
//  Box2d
//
//  Created by Dan on 3/8/14/Users/dan/Documents/CinderProjects/Box2d/xcode/box.h.
//
//

#pragma once
#include "particleSystem.h"

using namespace ci;

class box1 {
public:
    box1(){}
    box1(const ci::Vec2f &pos, b2World* world  );
    ~box1(){}
    void startContact();
    void endContact();
    void addBox();
    void update();
    void drawBox();
    bool isDead();
    int mNumContacts;
    

    Vec2f  getPosition();
    float & getAngle();

private:
    b2Body* mBody;
    b2World* mWorld;
    b2BodyDef bodyDef;
    b2PolygonShape dynamicBox;
    b2FixtureDef fixtureDef;

    float t;
    ci::Vec2f mPosition;
    int mLife;
    bool mDead;
    cinder::Color col;
   

};