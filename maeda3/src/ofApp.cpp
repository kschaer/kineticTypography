#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    textCenters.set(0,0);
    width = ofGetWidth();
    height = ofGetHeight();
    textBoundings.set(0,0,width,height);
    textReps = 1;
    yPos = 100;
    xPos = 0;
    
    ofSetColor(255);
    ofSetBackgroundColor(0);
    ofFill();
    pageCenter= 0;
    
    fontSize = 120;
    myFont.load("Avenir.ttc",fontSize,true,true,true);
    myText = "you are here";
    //ofSetFrameRate(2);
    
    textBounding.set(myFont.getStringBoundingBox(myText, 0, 0));
    
    textCenter.set(textBounding.width/2,textBounding.height/2);
    
    scalar = 0;
    
    ofEnableAntiAliasing();
    
    alignmentPoints.set(0,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    
    
    ofPushMatrix();
    //ofTranslate(mouseX,mouseY);
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);

    yPos = -50;
    
    ofBackground(0, 0, 0);
    for (int i = 0; i < 100; i++){
        float tempI = i;
        yPos = yPos+150./(tempI+1);
        textReps = 1+i;
        pageCenter = width/(textReps+1);
        for (int j = 0; j< textReps; j++){
            
            textBounding = myFont.getStringBoundingBox(myText, 0, 0);
            textCenter.set(textBounding.width/2, textBounding.height/2);
        
            xPos = pageCenter*(j+1);
    
            centerPoints.set(xPos,yPos);
            fontSize = 100/(tempI+2);
            ofSetColor(255);
            
            scalar = 127+127*sin(ofGetElapsedTimef());
            
            
            ofSetColor(240);
            
            
            ofRotateY(360*cos(.02*ofGetElapsedTimef()-j*i));
            ofPushMatrix();
            ofTranslate(xPos-1/(tempI+1), yPos+1/(tempI+1));
            
            
            //ofRotateX(180*sin(ofGetElapsedTimef()-i));
            ofRotateY(360*cos(.2*ofGetElapsedTimef()-j*i));
            ofRotateZ(180*sin(.1*ofGetElapsedTimef()-j));
            //ofRotateX(-90);
            
            
            ofScale(1/(tempI+1),1/(tempI+1));
            //            myFont.drawString(myText, xPos - textCenter.x, yPos + textCenter.x);
            myFont.drawString(myText, - textCenter.x ,  textCenter.y );
            //myFont.drawString(myText, - textCenter.x,  textCenter.y);
            
            //            myFont.drawString(myText, xPos - textCenter.x, yPos + textCenter.x)
            ofPopMatrix();
            
        }
        
    }
    //ofPopMatrix();
    cam.end();
    
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
