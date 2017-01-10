#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofDisableArbTex();
    ofEnableDepthTest();
    earth.load("earth_re.jpg");
    
    //GUI
    gui.setup();
    gui.add(latitude.set("latitude", 0,-90,90));
    gui.add(longitude.set("longitude", 0,-180,180));
    gui.add(radius.set("radius", 400, 250, 1000));
    gui.add(centerPoint.set("center", ofVec3f(0),ofVec3f(-1000),ofVec3f(1000)));
    
    
    
    
    
    //////////JSON
    //  http://techslides.com/list-of-countries-and-capitals
    
    std::string file = "example.json";
    
    // Now parse the JSON
    bool parsingSuccessful = sampleData.open(file);
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << sampleData.getRawString();
        
        // now write pretty print
        if (!sampleData.save("example_output_pretty.json", true))
        {
            ofLogNotice("ofApp::setup") << "example_output_pretty.json written unsuccessfully.";
        }
        else
        {
            ofLogNotice("ofApp::setup") << "example_output_pretty.json written successfully.";
        }
        
        // now write without pretty print
        if (!sampleData.save("example_output_fast.json", false))
        {
            ofLogNotice("ofApp::setup") << "example_output_pretty.json written unsuccessfully.";
        }
        else
        {
            ofLogNotice("ofApp::setup") << "example_output_pretty.json written successfully.";
        }
        
    }
    else
    {
        ofLogError("ofApp::setup")  << "Failed to parse JSON" << endl;
    }
    
    

    
    
    for( int i = 0; i<20; i++){
        CountryName[i] = sampleData[i]["CountryName"].asString();
        CapitalName[i] = sampleData[i]["CapitalName"].asString();
        CapitalLatitude[i] = sampleData[i]["CapitalLatitude"].asFloat();
        CapitalLongitude[i] = sampleData[i]["CapitalLongitude"].asFloat();
        Capital[i].orbit(CapitalLongitude[i] + 180, -CapitalLatitude[i], 200, centerPoint);
        
        CapitalPosX[i] = Capital[i].getX();
        CapitalPosY[i] = Capital[i].getY();
        CapitalPosZ[i] = Capital[i].getZ();
        //ofVec3f test
        CapitalPos[i].set(CapitalPosX[i], CapitalPosY[i],CapitalPosZ[i]);
        CapitalPos[i] = CapitalPos[i] * 1.3;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    node.orbit(longitude+180, -latitude, radius, centerPoint);
    camPosX = node.getX();
    camPosY = node.getY();
    camPosZ = node.getZ();
    
    
    

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofDrawBitmapString("X - Camera = " + ofToString(camPosX) , 220, 20);
    ofDrawBitmapString("Y - Camera = " + ofToString(camPosY) , 220, 35);
    ofDrawBitmapString("Z - Camera = " + ofToString(camPosZ) , 220, 50);
    


    if(ofGetKeyPressed(' ')){
        
        ofCamera c;
        c.setTransformMatrix(node.getGlobalTransformMatrix());
        c.begin();
//        ofDrawGrid(100,5,true);
        earth.bind();
        ofDrawSphere(200);
        earth.unbind();
        

        for(int i = 0; i < 20; i++) {
            ofSetColor(255,255,255);
            ofDrawBitmapString(CapitalName[i], CapitalPosX[i], CapitalPosY[i], CapitalPosZ[i]);
            ofSetColor(255,0,0);
            ofDrawSphere(CapitalPosX[i], CapitalPosY[i], CapitalPosZ[i], 0.5);
            
        }
        c.end();
        //cross line
        ofDisableDepthTest();
        ofDrawLine(ofGetWidth()/2-10, ofGetHeight()/2, ofGetWidth()/2+10, ofGetHeight()/2);
        ofDrawLine(ofGetWidth()/2, ofGetHeight()/2-10, ofGetWidth()/2, ofGetHeight()/2+10);
        
        ofEnableDepthTest();
   
    }else{
        
        cam.begin();
//        ofDrawGrid(100,5,true);
        node.draw();
        earth.bind();
        ofDrawSphere(200);
        earth.unbind();
        
        ofSetColor(255,0,0);
        for(int i = 0; i < 20; i++) {
            ofSetColor(255,255,255);
            ofDrawBitmapString(CapitalName[i], CapitalPosX[i], CapitalPosY[i], CapitalPosZ[i]);
            ofSetColor(255,0,0);
            ofDrawSphere(CapitalPosX[i], CapitalPosY[i], CapitalPosZ[i], 0.5);
            ofDrawLine(0, 0, 0, CapitalPos[i].x, CapitalPos[i].y, CapitalPos[i].z);
        }

        cam.end();
    }
    
    ofSetColor(255);
    
    ofDisableDepthTest();
    gui.draw();
    ofEnableDepthTest();
    
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
