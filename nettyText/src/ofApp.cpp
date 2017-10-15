#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableAntiAliasing();
    ofEnableSmoothing();
    ofHideCursor();
    
    bgColor.set(30);
    fgColor.set(220);
    ofBackground(bgColor);
    ofSetColor(fgColor);
    
    frameCount = 0;
    
    
    myText = "me\ncatch";
    textSize = 200;
    myFont.load("Arial Rounded Bold.ttf",textSize,true,true,true);
    textBounding.set(myFont.getStringBoundingBox(myText,0,0));
    centerText.set(-textBounding.width/2,-textBounding.height/2);
    
    
    
    

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    vector <ofTTFCharacter> textPaths = myFont.getStringAsPoints(myText);
    for (int i = 0; i < textPaths.size(); i++){
        vector <ofPolyline> polylines = textPaths[i].getOutline();
        for (int j = 0; j <polylines.size(); j++){
            vector <ofVec2f> linePoints;
            ofPolyline reSpacedPolyline = polylines[j].getResampledBySpacing(10);
            for (int k = 0; k < reSpacedPolyline.size(); k++){
                linePoints.push_back(reSpacedPolyline[k]);
                
                cam.begin();
                
                
                
                cam.end();
                
                
                
            }
            points.push_back(linePoints);
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
