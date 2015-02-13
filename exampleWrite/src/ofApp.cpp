#include "ofApp.h"
#include "ofxCsvStream.h"
ofxCsvStream csv;
//--------------------------------------------------------------
void ofApp::setup(){
    csv.openWriteStream("awesome.csv");
}

//--------------------------------------------------------------
void ofApp::update(){
    if ( ofGetFrameNum() % 10 == 0)
    {
        if ( ofGetFrameNum() > 0)
            csv << ",";
        csv << "you are a bad ass";
    }
    if ( ofGetFrameNum() % 30 == 0 && ofGetFrameNum() > 0)
    {
        csv << endl;
        csv << "you are a bad ass";
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

}

void ofApp::exit()
{
    csv.closeStream();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
