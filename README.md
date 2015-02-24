ofxAnalogTrigger

An ofxAddon for dealing with continous analog sensor values that have been discretized (through an A2D interface of some sort) that is then used for triggering events based on certain thresholds.

Why?

Consider this example: you have a infra-red sensor that measures the distance between an object and the sensor. It outputs a continous analog value which is digitized and sampled at some interval (say, 100 times a second). For simplicity's sake, the digital value you get is in the range of 0 to 100 (an integer), which corresponds to the active sensing range of the device of 0cm to 100cm. Now suppose you have a few different ways of using this sensor:

A.) As a presence sensor. This detects when someone gets close enough to it, and toggles a mode. This can be thought of as an "on/off" switch.  In this mode, we might simply do something like:

    if (sensorValue < DISTANCE) {
        //switch to ON mode
    }
    else {
        //switch to OFF mode
    }

    The potential issue with this, is if the sensor value is sitting at the boundary point at ~DISTANCE. In this case, due to noise in the analog circuitry, we may get rapid fluctuations that continuously toggle the mode between ON and OFF.

    One solution to this is after we are in the ON mode, we wait until the sensor value goes beyond a range from the threshold value before turning it off. This amount is the "deadband", where no action will be made. This is the first feature implemented by the class.

B.) If we want to use such a sensor as a trigger, say a mid-air 



Implemented features:

- Simple Thresholding
- Simple Thresholding with deadband

Future Work/Todo:

- Add event firing
- Time based filters for event firing


Created by Johnty Wang (full name followed by the googly mail thingy) Feb 2015


