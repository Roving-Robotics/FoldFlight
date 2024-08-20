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

1) motor shopping -> [hobbyking](https://hobbyking.com/en_us/power-systems/electric-motors.html#q=&idx=hbk_live_magento_en_us_products&dFR%5Bin_stock%5D%5B0%5D=1&dFR%5Bmotor_can_type%5D%5B0%5D=Outrunner&dFR%5Bmotor_features%5D%5B0%5D=Brushless%20-%20Sensorless&dFR%5Bwarehouses%5D%5B0%5D=USA&dFR%5Bwarehouses%5D%5B1%5D=Global&dFR%5Bwarehouses_stock_data%5D%5B0%5D=USA%7C3&dFR%5Bwarehouses_stock_data%5D%5B1%5D=Global%7C3&hFR%5Bcategories.level0%5D%5B0%5D=Power%20Systems%20%2F%2F%2F%20Electric%20Motors&nR%5Bhbk_price.stock_2_group_2%5D%5B<%3D%5D%5B0%5D=51&is_v=1)
2) the rest of the hardware: 
    - power dist board
    - flight controller
    - esc w: 4 independent motors & 4 servos *(two can be linked for transforming)*
3) fuselage & airfoils
    - design
    - construction
4) test flights #1
5) hinge mechanism/ slider
    - prototyping
    - implementation
6) test flgihts #2
7) flight controls
8) test flights #3  

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
