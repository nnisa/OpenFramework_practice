#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    mCircleRadius=100.f;
    ofSetCircleResolution(100.f);
    
    mPos = ofVec2f(ofGetWindowWidth()*0.5, ofGetWindowHeight()*0.5);
    
    mFriction = 0.99f;
    mAcceleration=ofVec2f(0);
    mVelocity=ofVec2f(0);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    mVelocity *= mFriction;
    //mVeloct
    mPos += mVelocity;
    
    if (mPos.x < 0) mPos.x = ofGetViewportWidth();
    if (mPos.y < 0) mPos.y = ofGetWindowHeight();
    if (mPos.x> ofGetViewportWidth()) mPos.x = 0;
    if (mPos.y>ofGetViewportHeight()) mPos.y=0;


}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(0);
    ofDrawCircle(mPos, mCircleRadius);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    ofVec2f mousePos= ofVec2f(x, y);
    mAcceleration = mousePos - mPos;
    float vecLenght= mAcceleration.length();
    mAcceleration= mAcceleration/ vecLenght;
    mVelocity+= mAcceleration;

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}


//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
    mPos+=mVelocity;
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
