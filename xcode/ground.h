//
//  ground.h
//  Box2d
//
//  Created by Dan on 3/9/14.
//
//
#include <Box2D/Box2D.h>
#pragma once

class ground {
public:
    ground(){}
    ground( b2World* world  );
    ~ground(){}
private:
    b2Body* mBody;
    b2World* mWorld;
    b2BodyDef bodyDef;
    ci::Vec2f mPosition;
};