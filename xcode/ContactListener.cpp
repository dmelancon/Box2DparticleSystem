//
//  ContactListener.cpp
//  Box2d
//
//  Created by Dan on 3/9/14.
//
//
#include <Box2D/Box2D.h>
#include "Box.h"
#include "ContactListener.h"

    void ContactListener::BeginContact(b2Contact* contact) {
        
        //check if fixture A was a box
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<box1*>( bodyUserData )->startContact();
        
        //check if fixture B was a box
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<box1*>( bodyUserData )->startContact();
        
    }
    
    void ContactListener::EndContact(b2Contact* contact) {
        
        //check if fixture A was a box
        void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<box1*>( bodyUserData )->endContact();
        
        //check if fixture B was a box
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( bodyUserData )
            static_cast<box1*>( bodyUserData )->endContact();
        
    }