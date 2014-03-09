//
//  ground.cpp
//  Box2d
//
//  Created by Dan on 3/9/14.
//
//

#include "ground.h"
#include <Box2D/Box2D.h>
#include "cinder/Rand.h"
using namespace ci;

ground::ground(b2World* world  ){
    mWorld = world;
    
    b2BodyDef groundBodyDef;
    groundBodyDef.type = b2_staticBody;
	groundBodyDef.position.Set( 0.0f, cinder::app::getWindowHeight() );
	b2Body* groundBody = mWorld->CreateBody(&groundBodyDef);
    
	// Define the ground box shape.
	b2PolygonShape groundBox;
    
	// The extents are the half-widths of the box.
	groundBox.SetAsBox(cinder::app::getWindowWidth(), 10.0f );
    
	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);
}


