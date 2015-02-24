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
    ofxAnalogTrigger();
    
    void enable() {
        ofAddListener(ofEvents().update, this, &ofxAnalogTrigger::update);
    }
    void disable() {
        ofRemoveListener(ofEvents().update, this, &ofxAnalogTrigger::update);
    }
    
    void update(ofEventArgs &args);
    
private:
    int timer;
    
    int mySensorValue_;
    int mySensorOffDeadband_;
    
    
};

#endif /* OFXANALOGTRIGGER_H_ */
