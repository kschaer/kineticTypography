#pragma once

#include "ofMain.h"

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
    
    ofPoint textCenters;
    ofRectangle textBoundings;
    
    float width;
    float height;
    
    
    ofPoint centerPoints;
    ofPoint alignmentPoints;
    
    float yPos;
    float xPos;
    
    float pageCenter;
    float textReps;
		
    
    float fontSize;
    
    float scalar;
    
    ofTrueTypeFont myFont;
    string myText;
    
    ofPoint textCenter;
    //ofVec2f centerer;
    ofRectangle textBounding;
    
};
