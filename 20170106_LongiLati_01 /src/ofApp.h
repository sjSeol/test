#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxJSON.h"

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
    
    ofxPanel gui;
    ofParameter<ofVec3f> centerPoint;
    ofParameter<float> latitude, longitude, radius;
    ofEasyCam cam;
    
    ofNode node;
    
    
    
    
    ofImage earth;
    
    int camPosX;
    int camPosY;
    int camPosZ;
    
    ofNode SJ;
    string SJ_name;
    float SJ_latitude;
    float SJ_longitude;
    float SJ_PosX;
    float SJ_PosY;
    float SJ_PosZ;
    
    ofNode Capital[20];
    string CountryName[20];
    string CapitalName[20];
    float CapitalLatitude[20];
    float CapitalLongitude[20];
    float CapitalPosX[20];
    float CapitalPosY[20];
    float CapitalPosZ[20];
    ofVec3f CapitalPos[20];
    

    
    
    //JSON
    ofxJSONElement sampleData;
		
};
