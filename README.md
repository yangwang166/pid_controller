# Overview
This repository contains all the code needed to complete the PID controller project

## Build

```
./go.sh
```

## Run

```
./run.sh
```

[//]: # (Image References)

[image1]: images/result.png "Result"

## Reflection

### The effect of the P, I, D components 

* The `P` stand for `Proportional` component. This component can help to set the steering angle in proportion to the `CTE`(Cross Track Error). This components try to keep the vehicle stick to the center of the lane. But if only use P component, the vehicle tend to overshot from the road and the vehicle will oscillate around the center of lane.

* The `I` stand for `Integration` component. This component will help to relieve the systematic Bias, such as the steering drift.

* The `D` stand for `Differential` component. This component can help to counteract the side effect of `P` component, which let the car overshoot the road and oscillation around the center of the lane. When we choose a good `D` parameter, we can observe the vehical drive smoothly around the center of lane.


### Describe how the final hyperparameters were chosen.

I am using the manual tuning method to choose the hyper-parameters. There are also other methods such as Twiddle and SGD and I will try these methods in next phase.

#### Here is my final hyper-parameters:

* P = 0.2
* I = 0.0001
* D = 2.0

#### Here is my approach:

1. Start from `P=0, I=0, D=0`
2. Gradually increase `P` until I observed a regularly and steady oscillation.
3. Then Gradually increase `D` until I observed the oscillation effect got constraint and goes away.
4. Loop between steps 2 and steps 3 until I couldn't see an obvious different
5. Increase the `I` parameters slightly until I got an acceptable result.

![result][image1]

