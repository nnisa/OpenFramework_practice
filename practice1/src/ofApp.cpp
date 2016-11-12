#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.load("photo.jpg");
    

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofGetWindowWidth/2 will create the image from the center from its corner which means technically it won't be in the center
    image.draw(ofGetWindowWidth()/2 -300, ofGetWindowHeight()/2 -300, 100, 100);
    
    

}
