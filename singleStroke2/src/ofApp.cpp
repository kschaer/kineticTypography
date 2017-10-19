#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    int circleResolution = 6;
    circlePolyline.arc(0,0,0,1,1,0,360,circleResolution);
    circlePoints.resize(circlePolyline.size());
    path.setFilled(false);
    
    for (int i=0; i< 20; i++)
    {
        for (int j=0; j< 20; j++)
        {
            drawCircle(i*40, j*40, 0, 20);
        }
        
    }
    
    for (int i=0; i<path.getCommands().size(); i++)
    {
        vector<ofPath::Command>& pathCommands = path.getCommands();
        for (int j=0; j<pathCommands.size(); j++)
        {
            commands.push_back(pathCommands[j]);
        }
        
    }
    
    commandIndex =0;
    


}

//--------------------------------------------------------------
void ofApp::update(){

    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    if (ofGetFrameNum()%10 == 0)
    {
        if (commandIndex+1<commands.size())
        {
            commandIndex++;
        }else {
            commandIndex = 0;
        }
    }
    polyline.clear();
    int curveResolution = ofGetStyle().curveResolution;
    //maybe a better way?
    ofPath tempPath;
    int arcResolution = tempPath.getCircleResolution();
    
    
    for(int i=0; i<commandIndex; i++)
    {
        switch(commands[i].type)
        {
            case ofPath::Command::moveTo:
                polyline.moveTo(commands[i].to);
                break;
            case ofPath::Command::lineTo:
                polyline.lineTo(commands[i].to);
                break;
            case ofPath::Command::curveTo:
                polyline.curveTo(commands[i].to);
                //                polyline.curveTo(commands[i].to, curveResolution);
                break;
            case ofPath::Command::bezierTo:
                polyline.bezierTo(commands[i].cp1,commands[i].cp2,commands[i].to);
                //                polyline.bezierTo(commands[i].cp1,commands[i].cp2,commands[i].to, curveResolution);
                break;
            case ofPath::Command::quadBezierTo:
                //                polyline.quadBezierTo(commands[i].cp1,commands[i].cp2,commands[i].to, curveResolution);
                polyline.quadBezierTo(commands[i].cp1,commands[i].cp2,commands[i].to);
                break;
            case ofPath::Command::arc:
                //                polyline.arc(commands[i].to,commands[i].radiusX,commands[i].radiusY,commands[i].angleBegin,commands[i].angleEnd, arcResolution);
                polyline.arc(commands[i].to,commands[i].radiusX,commands[i].radiusY,commands[i].angleBegin,commands[i].angleEnd);
                
                break;
            case ofPath::Command::arcNegative:
                //                polyline.arcNegative(commands[i].to,commands[i].radiusX,commands[i].radiusY,commands[i].angleBegin,commands[i].angleEnd, arcResolution);
                polyline.arcNegative(commands[i].to,commands[i].radiusX,commands[i].radiusY,commands[i].angleBegin,commands[i].angleEnd);
                break;
            case ofPath::Command::close:
                polyline.close();
                //                polylines.push_back(polyline);
                //                polyline.clear();
                break;
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofPushMatrix();
    ofSetColor(ofColor::yellow);
    ofTranslate(20, 20, 0);
    //    for(int i=0;i<polylines.size();i++){
    //        polylines[i].draw();
    //    }
    
    polyline.draw();
    ofPopMatrix();
    
}
//--------------------------------------------------------------

void ofApp::drawCircle(float x, float y, float z,  float radius){
    vector<ofPoint> & circleCache = circlePolyline.getVertices();
    for(int i=0;i<(int)circleCache.size();i++){
        circlePoints[i].set(radius*circleCache[i].x+x,radius*circleCache[i].y+y,z);
        if(i==0)
        {
            path.moveTo(circlePoints[i]);
            
        }else
        {
            path.lineTo(circlePoints[i]);
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
