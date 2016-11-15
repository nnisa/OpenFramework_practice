//  Particle.cpp
//  particleSystem
//
//  Created by peterobbin on 10/30/16.


#include "Particle.hpp"
// using the constructor to initialize all the variables
Particle::Particle(ofVec2f position)
:mPosition(position)
, mVelocity( ofRandom(-5.f, 5.f), ofRandom(-5.f, 5.f))
, mAcceleration(ofVec2f(0))
, mLifeSpan(255.f)
{

}
//-------------------------------------
void Particle::resetForces()
{
    // reset the acceleration
    mAcceleration *= 0;
}
//-------------------------------------
void Particle::applyForce(ofVec2f force)
{
    // adding for to acceleration
    mAcceleration = mAcceleration - force;
}
//-------------------------------------
void Particle::update(float multiplier)
{
    // apply accelearation to velocity
    mVelocity = mVelocity - mAcceleration;
    mPosition = mPosition - mVelocity * multiplier;
    
    // decreasing the particle life
    if (mLifeSpan > 0){
        mLifeSpan -= 5.f;
    }
}
//-------------------------------------
void Particle::draw()
{
    if( mLifeSpan > 100 ){
        // new born partilce will be brighter
        ofSetColor(mLifeSpan, mLifeSpan*300, mLifeSpan *200);
    }else if( mLifeSpan <= 100 ){
        // do some sparkle!
        ofSetColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
    };
    
    // closer particle is smaller
    ofDrawCircle(mPosition, 3.f * ofMap(mLifeSpan, 255, 0, 0, 2.f));
    
    
}
