#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(20);
    ofSetColor(80);
    
    mappedMouse = 0;
    
    myString = "disco";
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    time = ofGetElapsedTimef();
    sinTime = sin(time);
    cosTime = cos(time);
    
    fontScale = 11;
    myFontPath = myFont.getPath(myString, fontScale);
    
    vector <ofPolyline> polylines = myFontPath.getOutline();
    for (int i = 0; i < polylines.size(); i++){
        vector <ofVec2f> linePoints;
        ofPolyline reSpacedPolyline = polylines[i].getResampledBySpacing(2);
        for (int j = 0; j<reSpacedPolyline.size(); j++){
            linePoints.push_back(reSpacedPolyline[j]);
        }
        points.push_back(linePoints);
    }

    


}

//--------------------------------------------------------------
void ofApp::update(){


    
}

//--------------------------------------------------------------


void ofApp::draw(){
    
    time = ofGetElapsedTimef();
    sinTime = sin(time);
    cosTime = cos(time);
    mappedMouse = ofMap(mouseX,0,width,-.2,2);
    //mappedMouse = -.197;
    
    //cam.enableOrtho();
    cam.begin();
    
    ofPushMatrix();
    ofRotateX(180);
    
    for (int i = 0; i< points.size(); i++){
        vector <ofVec2f> wordPoints = points[i];
        for (int j = 0; j < wordPoints.size(); j++){
            float tempI = i;
            float tempJ = j;
            ofPoint wiggle2D;
            
//            ofPoint maxPoint;
//            maxPoint.set(wordPoints[wordPoints.size()-1]);
//            ofPoint minPoint;
//            minPoint.set(wordPoints[0]);
//            float textWidth = ofDist(minPoint.x, minPoint.y, maxPoint.x, maxPoint.y);
            
            wiggle2D.set(5*cos(.5*time-.1*tempJ),5*sin(.5*time-.1*tempJ),10*cos(.5*time-.1*tempJ));
            
            ofPoint zWiggle;
            //zWiggle.set(0,0,10*cos(time-.1*tempJ)+20*sin(.3*time-.03*i));
            zWiggle.set(0,0,15*cos(ofGetElapsedTimef()-.05*j)+80*sin(.4*ofGetElapsedTimef()-i));
            ofPoint newPoints;
            newPoints.set(wordPoints[j]+wiggle2D+zWiggle);
            
            
            ofPushMatrix();
            ofTranslate(-width/3-60,60);
            ofTranslate(newPoints);
            

            ofSetColor(ofMap(sin(time-.1*j),-1,1,100,240),ofMap(sin(time+mappedMouse*j),-1,1,100,240),ofMap(sin(time-mappedMouse*j),-1,1,30,255));
            ofDrawBox(0,0,.5*zWiggle.z, (10+13*sin(time+.195*j))+10*cos(time-.02*j) );
            ofPopMatrix();
            

            
        }
    }

    ofPopMatrix();
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
