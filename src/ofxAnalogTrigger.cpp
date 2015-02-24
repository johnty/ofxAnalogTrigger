//
//  ofxAnalogTrigger.cpp
//  exampleICubeX
//
//  Created by johnty on 2015-02-20.
//
//

#include "ofxAnalogTrigger.h"
#include "ofMain.h"

ofxAnalogTrigger::ofxAnalogTrigger(int min, int max, int thres, int deadband) {
    mySensorMin_ = min;
    mySensorMax_ = max;
    mySensorThres_ = thres;
    myDeadband_ = deadband;
}

void ofxAnalogTrigger::update(ofEventArgs &args) {
    ofLogNotice("trigger update") << "trigger update" <<endl;
    //do timing related checks here
    
}

void ofxAnalogTrigger::updateValue(int val) {
    mySensorValue_ = val;
    ofLogNotice("updateVal") << val <<endl;
    //do transition checks here
}
