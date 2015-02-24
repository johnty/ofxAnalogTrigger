//
//  ofxAnalogTrigger.h
//  exampleICubeX
//
//  Created by johnty on 2015-02-24.
//
//

#ifndef OFXANALOGTRIGGER_H_
#define OFXANALOGTRIGGER_H_

#include "ofEvents.h"

class ofxAnalogTrigger {
    
public:
    ofxAnalogTrigger(int min=0, int max=127, int thres = 50, int deadband = 0);
    
    void enable() {
        ofAddListener(ofEvents().update, this, &ofxAnalogTrigger::update);
    }
    void disable() {
        ofRemoveListener(ofEvents().update, this, &ofxAnalogTrigger::update);
    }
    
    void update(ofEventArgs &args);
    void updateValue(int val);

    void setMin(int val) {mySensorMin_ = val;}
    void setMax(int val) {mySensorMax_ = val;}
    void setThres(int val) {mySensorThres_ = val;}
    void setDeadBand(int val) {myDeadband_ = val;}
    
private:
    int timer;
    
    int mySensorValue_;
    int mySensorOffDeadband_;
    
    int mySensorMin_;
    int mySensorMax_;
    int mySensorThres_;
    int myDeadband_;
    
    
};

#endif /* OFXANALOGTRIGGER_H_ */
