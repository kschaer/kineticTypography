#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myFont.setColor(100);
    //ofBackgroundGradient(200, 100);
    ofBackground(0);
    ofSetColor(10, 50, 100);
    width = ofGetWidth();
    height = ofGetHeight();
    
    //ofNoFill();
    ofSetLineWidth(2.2);
    
    
    myFontPath = myFont.getPath("pathyPATH",5);
    myFontPath.setStrokeColor(255);
    myFontPath.setFillColor(ofColor(255,20,100));
    myFontPath.setFilled(true);
    //myFontPath.setMode(ofPath::POLYLINES);
    
    
    vector <ofPolyline> polylines = myFontPath.getOutline();
    for (int i = 0; i < polylines.size(); i++){
        vector <ofVec2f> linePoints;
        ofPolyline reSpacedPolyline = polylines[i].getResampledBySpacing(4);
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

   // myFont.draw("helloWorld" , 100, 100, 3, false , 0);
    //myFontPath = myFont.getPath("helloWorldPath",3);
    cam.begin();
    
    ofPushMatrix();
    ofRotateX(-180);
    ofTranslate(-width/2+ width/8,0);
//    ofRotateX(mouseX);
//    myFontPath.draw(0,0);
    
    for (int i = 0; i < points.size(); i++){
        vector <ofVec2f> wordPoints = points[i];
        for (int j = 0; j < wordPoints.size(); j++){
            float tempI = i;
            ofPoint wigglingPoint;
            cout << points.size() << endl;
            ofSetColor(255-ofMap(i,0,points.size(),0,255), ofMap(i,0,points.size(),0,255), ofMap(i,0,points.size(),0,255));

            wigglingPoint.set(j*sin(1*ofGetElapsedTimef()), 10*sin(1*ofGetElapsedTimef()-tempI),0);
            ofPoint newPoint = wordPoints[j]+wigglingPoint;
            ofPushMatrix();
                ofTranslate(newPoint);
                ofRotateY(360*sin(ofGetElapsedTimef()-j));
                ofPoint zeroPoint;
                zeroPoint.set(0,0,0);
                ofDrawCircle(zeroPoint, 2+j%5);

                ofPoint basePoint;
        
                basePoint.set(width/i, height/2, 0);
            ofPopMatrix();
            
            //ofDrawLine(newPoint, basePoint);
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
