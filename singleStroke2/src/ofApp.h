#pragma once

#include "ofMain.h"
#include "ofxHersheyFont.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofxHersheyFont myFont;
    ofPath myFontPath;
    ofPath outline;
    float fontScale;
    
    
    float width;
    float height;
    float time;
    
    float sinTime;
    float cosTime;
    
    float mappedMouse;

    
    vector <vector <ofVec2f> > points; //*******
    string myString;
    
    ofEasyCam cam;
    
};
