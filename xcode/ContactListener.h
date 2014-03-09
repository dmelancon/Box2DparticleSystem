//
//  ContactListener.h
//  Box2d
//
//  Created by Dan on 3/9/14.
//
//

#pragma once

class ContactListener : public b2ContactListener
{
    void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact);
};