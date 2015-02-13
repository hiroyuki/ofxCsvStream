#include "ofApp.h"
#include "ofxCsvStream.h"
ofxCsvStream stream;
vector<string> data;

//--------------------------------------------------------------
void ofApp::setup(){
    stream.openReadStream("awesome.csv");
}

//--------------------------------------------------------------
void ofApp::update(){
    if( ofGetFrameNum() % 100 == 0)
    {
        if ( !stream.eof())
        {
            stream.readNextLine();
            for (int i = 0; i < stream.getCurrentTokenSize(); i++) {
                data.push_back(stream.getValue<string>(i));
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for ( int i = 0; i < data.size(); i++ )
    {
        ofDrawBitmapString(data[i], ofPoint(10, i * 15));
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
