# FoldFlight
An amphibious VTOL-UAV to demonstrate mechanical design and controls implementation.

## Collaborators:

[Ian Wilhite](linkedin.com/in/ian-wilhite)
- Electrical Systems
- Flight Controls
- Communication Protocols

[Victor Cardona](linkedin.com/in/victor-cardona-6b6856235/)
- Airfoil Design & Assembly
- Fuselage Balancing
- Folding Mechanism 


## Research:
- [inspo design](https://pterodynamics.com)
- [design spec ratios](https://www.radiocontrolinfo.com/rc-calculators/rc-airplane-design-calculator/)
- [motor calculator](https://rcplanes.online/calc_motor.htm)
- Thrust to weight ratio should be 1.3~1.5 (should round up)
- Weight probably 10 lbs (assume 15lbs)
- Lift coefieccient should be determined experimentally, should be 1~1.5 (should round down)
- 

## To Do:

1) the rest of the hardware: 
    - power dist board -> leftover
    - flight controller -> arduino uno & rc controller -> leftover
    - escs for each motor -> attached to leftover motors
    - rc transmitter and reciever -> bought
    - 
2) fuselage
    - design
    - construction -> lasercut ribs, wrap in abs w/ heat gun
3) airfoil
    - [design - NACA 2412](http://www.airfoiltools.com/airfoil/details?airfoil=naca2412-il)
4) test flight #1: standard fixed wing flight
5) hinge mechanism/ slider
    - prototyping
    - implementation
    - design -> will determine fuseloge design
    a) idea 1: I beam roller
        - i beam along bottom of fuseloge, bearing roller cart on belt along track run by stepper motor
    b) idea 2: Worm gear drive
        - cart moves along worm gear also driven by stepper motor
6) test flgihts #2: standard quadcopter flight w mechanism
7) flight controls
8) test flights #3: in flight transformation

## Brainstorming 

### Flight Dynamics Brainstorming:

#### Constant elevation transform: 

* Pros:
    - stable
    - easy to recognize errrors 
    - better for cameras/sensors
* Cons:
    - more challenging
    - would require model driven control system (probably)
* Notes:
    Could start moving forward in quad mode then transform & let moving masses level out, or focus on hovering level and let forward thrust accelerate

#### Nose-dive transform
* Pros:
    - easier for manual control
    - does not require force to hover while transforming
* Cons: 
    - requires higher starting elevation
    - high likelyhood of crashing during testing
    - less productive for final applications
* Notes:
    Depends on sensor load - can be decided later in the design process

### Folding Mechanism Brainstorming:

#### Cycloidal drive on hinge:
* Pros:
    - not backdrivable, little wiggle
    - would be really cool
    - servo position data stream on wing position for flight control model
    - independent wing control
* Cons: 
    - puts high pressure on small parts
    - key failure point
    - complicated - smaller parts are more prone to breaking
    - independent wing control means a potential for unequal folding 
* Notes:
    Would be a cool application, but don't shoehorn a cool thing into a project that doesn't need it

#### Track based four bar linkage
* Pros
    - stronger
    - easier to model
    - find a belt drive mechanism that can give position data
    - both halves can be physically linked - stronger (fewer points of failure)
* Cons
    - takes up fuselage space
    - hurts aerodynamics
* Notes:
    Very likely the better candidate - will continue to look for alternatives


