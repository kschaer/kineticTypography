#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    textCenters.set(0,0);
    width = 512;
    height = 1024;
    textBoundings.set(0,0,width,height);
    textReps = 1;
    yPos = 100;
    xPos = 0;
    
    ofSetColor(255);
    ofSetBackgroundColor(0);
    ofFill();
    pageCenter= 0;
    
    fontSize = 20;
    myFont.load("Avenir.ttc",fontSize,true,true,true);
    myText = "hello";
    //ofSetFrameRate(2);

    textBounding.set(myFont.getStringBoundingBox(myText, 0, 0));

    textCenter.set(textBounding.width/2,textBounding.height/2);
}

//--------------------------------------------------------------
void ofApp::update(){
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    yPos = 0;

    ofBackground(0, 0, 0);
    for (int i = 0; i < 100; i++){
        float tempI = i;
        yPos = yPos+100./(tempI+1);
        textReps = 1+i;
        for (int j = 0; j< textReps; j++){
            pageCenter = width/(textReps+1);
           // fontSize = 200-5*textReps;
            myFont.setLineHeight(fontSize);
            myFont.getStringBoundingBox(myText, 0, 0);
            textCenter.set(textBounding.width/2, textBounding.height/2);
            //centerer.set
            //            if (i %2 == 0){
//                ofSetColor(255, 0, 255);
//            } else {
//                ofSetColor(0, 255, 255);
//            }
                //ofDrawCircle (pageCenter*(j+1), 20*(i+1), 10);
            xPos = pageCenter*(j+1);
            //yPos = 100;
            //yPos = yPos+yPos-(100/(i+1));
            
            //ofDrawCircle(xPos,yPos,fontSize/(tempI+1));
            centerPoints.set(xPos,yPos);
            fontSize = 100/(tempI+2);
            ofSetColor(255);
            //ofDrawCircle(centerPoints,fontSize);
            ofSetColor(220,200,10,255-10*textReps);
            //ofTranslate(mouseX,mouseY);
            myFont.drawString(myText, xPos - textCenter.x, yPos + textCenter.x);
            
        }
        
    }

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
