#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0, 0, 0);
    ofSetColor(255);
    
    myText = "hello";
    myFont.load("Avenir.ttc", fontSize, true,true,true);
    
    posY = 0;
    textReps = 1;
    fontSize = 100;
    textBounding.set(myFont.getStringBoundingBox(myText,0,0));
    posY = textBounding.height;
    posX = 0;
    centerText.set(textBounding.width/2,textBounding.height/2);
    fontScale = ofGetWidth()/textBounding.width; 

    ofNoFill();
    
    textPos.set(0,0);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i<10; i++){
        textReps = 1+2^i;
        for(int j = 0; j <textReps; j++){
            fontSize = 100-10*(i+1);
            myFont.load("Avenir.ttc", fontSize);
            //ofDrawCircle(100+30*i, 100+30*j, fontSize);
            textBounding.set(myFont.getStringBoundingBox(myText,0,0));

            myFont.drawString(myText, (textReps-1)*textBounding.width, 100);
        }
    }
    
    
    //ofPushMatrix();
//
//    for (int i = 0; i < 10; i++){
//        ofPushMatrix();
//        fontSize = 200/(i+1);
//        myFont.load("Avenir.ttc", fontSize, true,true,true);
//        textBounding.set(myFont.getStringBoundingBox(myText,0,0));
//        textReps = (2^i);
//        posY = posY+textBounding.height;
//        ofTranslate(0, posY);
//
//
//        for (int j = 0; j <textReps; j++){
//            ofPushMatrix();
//
//            ofTranslate(textBounding.width*j,0);
//
//            myFont.drawString(myText,0,0);
//            
//            ofPopMatrix();
//    }
//
//        ofPopMatrix();
//    }
    //ofPopMatrix();
    
    
    //--------------------------------------------
    
//    for (int i = 0; i < 1; i++){
//        textReps = 2^i;
//        for (int j = 0; j < textReps; j++){
//            ofPushMatrix();
//            fontScale = ofGetWidth()/(textBounding.width*textReps);
//            //ofScale(1/fontScale,1/fontScale);
//            //ofTranslate(mouseX*i, mouseY*j);
//            myFont.drawString(myText, 100 , 100);
//            ofPopMatrix();
//            
//        }
//    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
