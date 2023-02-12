#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetColor(255);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);

	if (ofGetFrameNum() % 240 < 60) {

		ofBackground(ofMap(ofGetFrameNum() % 240, 0, 60, 0, 255));
		ofSetColor(ofMap(ofGetFrameNum() % 240, 0, 60, 255, 0));
	}
	
	if(ofGetFrameNum() % 240 > 120 && ofGetFrameNum() % 240 < 180) {

		ofBackground(ofMap(ofGetFrameNum() % 240, 120, 180, 255, 0));
		ofSetColor(ofMap(ofGetFrameNum() % 240, 120, 180, 0, 255));
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	for (int i = 0; i < 200; i++) {

		auto x = ofRandom(-600, 600);
		auto y = ofRandom(-600, 600);
		auto z = (int)(ofRandom(1200) + ofGetFrameNum() * 20) % 1200 - 600;

		ofDrawLine(glm::vec3(x, y, z), glm::vec3(x, y, z - 30));
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
