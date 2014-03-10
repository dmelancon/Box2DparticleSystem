//
//  particleSystem.h
//  Box2d
//
//  Created by Dan on 3/9/14.
//
//

#pragma once

struct Particle {
    ci::Vec2f mPosition;
    ci::Vec2f mVelocity;
    ci::Vec2f mAcceleration;
    int mLife;
};

class particleSystem {
    
public:
    
    particleSystem();
    particleSystem(int, ci::Vec2f, float);
    ~particleSystem();
    void update();
    void addParticles();
    bool isDead();
    void draw();
    int mSize;
    int mPos;
    float angle;
private:
    std::list<Particle> mParticles;
    float x;
};