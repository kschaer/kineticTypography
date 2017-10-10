#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(14);
    ofEnableAntiAliasing();
    ofEnableSmoothing();
    
    frameCount = 0;

    myText = "hi!";
    myFont.load("Arial Rounded Bold.ttf",450,true,true,true);
    //myFont.loadFont("Skia.ttf", 100);
    textBounding.set(10,10,10,10);
    centerText.set(0,0);
    
    ofSetLineWidth(.5);
    
    ofSetColor(0);
    //enableOrtho();
    
    ofHideCursor();

    
    
    //get the string myText of myFont as paths
    vector <ofTTFCharacter> paths = myFont.getStringAsPoints(myText);
    for (int i = 0; i <paths.size(); i++){
        //for every character in the string, is a separate polyline
        vector <ofPolyline> polylines = paths[i].getOutline();
        //for every polyline...
        for (int j = 0; j <polylines.size(); j++){
            //create a vector to store all points of a single polyline
            vector <ofVec2f> linePoints;
            // and then resample that polyline to acheive equal spacings
            ofPolyline reSpacedPolyline = polylines[j].getResampledBySpacing(10);
            //add all these resampled points into the vector for character points
            for (int k = 0; k < reSpacedPolyline.size(); k++){
                linePoints.push_back(reSpacedPolyline[k]);
                
                
                
                
                
                
                ofPushMatrix();
                
                textBounding.set(myFont.getStringBoundingBox(myText,0,0));
                centerText.set(-textBounding.width/2,20-textBounding.height/2);
                ofTranslate(centerText);
                //myFont.drawString(myText,0,0);
                
                ofPopMatrix();
            }
            //put the vector of points back into the main vector
            points.push_back(linePoints);
            
            
        }
    }
    nextPointSpeed = 0;
    rotateSpeed = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    //nextPointSpeed = ofMap(mouseX,0, ofGetWidth(),.0001,1);
    nextPointSpeed =.4;
    rotateSpeed = ofMap(mouseY,0, ofGetHeight(),0,1);
    frameCount = (int)(ofGetFrameNum()*nextPointSpeed);
    
    
    
    for (int i = 0; i<points.size(); i++){
        vector <ofVec2f> charPoints = points[i];
        for (int j = 0; j <charPoints.size(); j++){
            
            ofPushMatrix();
    
    textBounding.set(myFont.getStringBoundingBox(myText,0,0));
    centerText.set(-textBounding.width/2-10,-textBounding.height/2);
            
    //ofTranslate((ofGetWidth()-textBounding.width)/2,ofGetHeight()/2);
            
            ofSetColor(180+50*sin(ofGetElapsedTimef()-.05*j));
            //ofTranslate(mouseX, mouseY);
            //ofRotateY(-360+(360*rotateSpeed*cos(ofGetElapsedTimef())));
            //ofRotateY(ofMap(mouseY,0,ofGetHeight(),-360,360));
            ofRotateY(30*sin(ofGetElapsedTimef()*.1));

            ofTranslate(centerText);
      //      ofRotateX(-180+(360*cos(ofGetElapsedTimef()*.5)));
            ofRotateX(-180);
            ofPoint wigglingPoint;
//            vector <ofPoint> wigglingPoint;
            
//            wigglingPoint.set(5*sin(ofGetElapsedTimef()-.10*j), 5*sin(ofGetElapsedTimef()*.1),.6*j*cos(ofGetElapsedTimef()*.2*j));
            wigglingPoint.set(0,0,10*(j%10)*sin(ofGetElapsedTimef()));
            
            //charPoints[j] = charPoints[j] + wigglingPoint;
            
            ofDrawLine(charPoints[j], wigglingPoint + charPoints[(j+frameCount)% charPoints.size()]);
            ofSetColor(255);
            //ofSetColor(mouseY, 255/(j+1), 200);
            //ofFill();
            //ofDrawSphere(charPoints[j], 5);
            
            ofDrawCircle(wigglingPoint + charPoints[(j+frameCount)% charPoints.size()], (j+1)%4);
            
            for (int k = 0; k < 1000; k++){
                
            }
            
//            ofSetColor(30);
//            ofPoint vanishingPoint;
//            vanishingPoint.set(0,0,400);
//            vanishingPoint = vanishingPoint-centerText;
//            
//            ofDrawLine(wigglingPoint + charPoints[(j+frameCount)% charPoints.size()],vanishingPoint);


    
    //myFont.drawString(myText,0,0);
    
    ofPopMatrix();
        }

    }
    
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
