//
//  ofxAnalogTrigger.cpp
//  exampleICubeX
//
//  Created by johnty on 2015-02-20.
//
//

#include "ofxAnalogTrigger.h"
#include "ofMain.h"

ofxAnalogTrigger::ofxAnalogTrigger(int min, int max, int thres, int deadband, bool isActiveLow) {
    mySensorMin_ = min;
    mySensorMax_ = max;
    mySensorThres_ = thres;
    myDeadband_ = deadband;
    mySensorIsActiveLow_ = isActiveLow;
}

void ofxAnalogTrigger::update(ofEventArgs &args) {
    ofLogNotice("trigger update") << "trigger update" <<endl;
    //do timing related checks here
    
}

void ofxAnalogTrigger::updateValue(int val) {
    mySensorValue_ = val;
    ofLogNotice("updateVal") << val <<endl;
    //do transition checks here
    
    if (mySensorState_ == SENSOR_IDLE) { //IDLE STATE
        //timer case
        if (mySensorTimePeriod_ms_ >= 0) {
            
        }
        else { //no timer case
            if (val>mySensorThres_) { //GOTO ACTIE STATE
                ofNotifyEvent(sensorActivatedEvent, val, this);
            }
        }
        
        
    }
    else if (mySensorState_ == SENSOR_ACTIVE){ //ACTIVE STATE
        //GOTO FALLING STATE
        
        //GOTO IDLE STATE
    }
    
    
}
