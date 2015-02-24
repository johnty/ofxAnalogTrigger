ofxAnalogTrigger

An ofxAddon for dealing with continous analog sensor values that have been discretized (through an A2D interface of some sort) that is then used for triggering events based on certain thresholds.

Why?

Consider this example: you have a infra-red sensor that measures the distance between an object and the sensor. It outputs a continous analog value which is digitized and sampled at some interval (say, 100 times a second). For simplicity's sake, the digital value you get is in the range of 0 to 100 (an integer), which corresponds to the active sensing range of the device of 0cm to 100cm. Now suppose you have a few different ways of using this sensor:

A.) You want to use it as a presence sensor to detect when someone gets close enough to it, and toggles a mode. This can be thought of as an "on/off" switch.  In this mode, we might simply do something like:

    if (sensorValue < DISTANCE) {
        //switch to ON mode
    }
    else {
        //switch to OFF mode
    }

The potential issue with this, is if the sensor value is sitting at the boundary point at ~DISTANCE. In this case, due to noise in the analog circuitry, we may get rapid fluctuations that continuously toggle the mode between ON and OFF.

One solution is once in the ON mode, we wait until the sensor value goes beyond a range from the threshold value before turning it off. This amount is the "deadband", where no action will be made and will make the state much more stable. This is the first feature implemented by the class.

B.) If we're simply using the state of the sensor (either ON or OFF) to drive a value that needs to or can be updated constantly, then we can simply use the loop in A. However, if we need to generate once-off triggers when we transition between the two modes, we'd have to make some additional variables

C.) Finally, we may want to limit for how long are we beyond a certain threshold for the internal state (and triggers) to change between ON and OFF. This requires a timer that starts counting once a threshold has been reached, but the state transition is held until a preset amount of time has elapsed. This is useful for cases where you don't want random transients in the signal to create false triggers. Of course, this has the tradeoff of not being able to detect very sharp movements, so it depends on what you're trying to do. For example, if you're building a drug trigger, you probably don't want to use this. On the other hand, if you're  building a presence detector for an installation, you might want to make sure your sensor value corresponds to someone actively engaging with the application, as opposed to a passer by who briefly triggers the sensor.



Usage:

- Place code in oF addons folder, as per regular ofxAddons
- Declare an instance of the class for each sensor trigger
- (if using triggers) create callback functions in your main ofApp for transitions you want to listen to, such as:
-   - LowToHigh()
-   - HighToLow()

- In setup(), do the following:
-   - set the value range (default: 0-127, threshold=50, time = 0 ms)
-   - (if using triggers) connect callback functions such as LowToHigh() etc, to 
-   - enable the trigger via .enable() a
-   - 
- In update() loop, update the value of the sensor object using .updateVal()
- In 


Implemented features:

- Simple Thresholding
- Simple Thresholding with deadband

Future Work/Todo:

- Add event firing
- Time based filters for event firing


Created by Johnty Wang (full name followed by the googly mail thingy) Feb 2015


