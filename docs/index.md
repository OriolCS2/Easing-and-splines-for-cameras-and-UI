# Easing and splines for cameras and UI
I am [Oriol Capdevila Salinas](https://www.linkedin.com/in/oriol-capdevila-0a6b3914b/), student of the [Bachelor’s Degree in Video Games by UPC at CITM](https://www.citm.upc.edu/). This content is made for the second year’s subject Project 2, under supervision of lecturer [Ricard Pillosu](https://www.linkedin.com/in/ricardpillosu?originalSubdomain=es).
# Problem & Solution
We have some problems when we have to move the camera or some UI because we just had one way to do it:

`App->render->camera.x -= 100*dt;`

We had to put a condition in order to finish it when we wanted. This might be fine for simple games and simple camera movements, but how could we have done this movement with this system: (the speed decreases with time) 

![](https://im5.ezgif.com/tmp/ezgif-5-c1046f1efd98.gif)

It is not a difficult movement, but with our old system, this must have been hardcoded. So, my objective is that to make this movement and far more with just calling a function once, let's start.

![](https://i.gyazo.com/cbe1999d34d513cb9b89c1823d0b2a61.png)

# Introduction to Splines
In mathematics, a spline is a piecewise function defined by polynomials. This functions are usually used in programming because of the simplicity of their construction, their ease and accuracy of evaluation.  
## Easing Functions 
These functions as its name says, are simplified functions that help to resolve difficult functions and their result is really accurated. These will give us the chance to use splines with a really easy method. They depend on four parameters:

* **Current Time (t):** Time that has passed since the spline started. 
* **Initial Value (b):** In our case, the initial position of the element that we want to move.
* **Final Value (c):** In our case, the final position we want to have our element at the end of the spline.
* **Duration (d):** The time we want to complete the spline.

In my code, these parameters have a different name because I think they are more readable:

* **Current Time (t):** time_passed
* **Initial Value (b):** initial_position
* **Final Value (c):** distance_to_travel
* **Duration (d):** time_to_travel

## Easing Functions Types

Using a power that its range is from 1 to 6:

* **Linear:** Power of 1.

![](https://im5.ezgif.com/tmp/ezgif-5-7d44f0548760.gif)

* **Quad:** Power of 2.

![](https://im5.ezgif.com/tmp/ezgif-5-12148db323ec.gif)

* **Cubic:** Power of 3.

![](https://im5.ezgif.com/tmp/ezgif-5-14011f8ffa59.gif)

* **Quart:** Power of 4.

![](https://im5.ezgif.com/tmp/ezgif-5-32b1d8114393.gif)

* **Quint:** Power of 5.

![](https://im5.ezgif.com/tmp/ezgif-5-c7cb04e8f3eb.gif)

* **Circ:** Power of 6.

![](https://im5.ezgif.com/tmp/ezgif-5-e00218fe7101.gif)

Some others that use differents math methods:

* **Back:** The object bypass the objective and then returns.

![](https://im5.ezgif.com/tmp/ezgif-5-57d6d18f8bb9.gif)

* **Expo:** Increases/decreases exponentially the initial value.

![](https://im5.ezgif.com/tmp/ezgif-5-b40162c2b221.gif)

Each ease function, less the linear, has three different functions:

* **Ease In:** Describe the positive acceleration of the element that is being moved.
* **Ease Out:** Describe the negative acceleration of the element that is being moved.
* **Ease In Out:** It is a combination of the two movements described above, first Ease In and the Ease Out. 

## Graphic Help of each Function

* **EaseInQuad:**

![](https://i.gyazo.com/9dc5d02e3bd29214bbbc1b9cf630c4d2.png)

* **EaseOutQuad:**

![](https://i.gyazo.com/f4c1dce3ebb72288517a0e53de95bf00.png)

* **EaseInOutQuad:**

![](https://i.gyazo.com/ca4ec06be452ef89fb381e4f0dc7170d.png)

* **EaseInCubic:**

![](https://i.gyazo.com/6cb77e6f3845cb89d4edc187764ef053.png)

* **EaseOutCubic:**

![](https://i.gyazo.com/8fa2fb1b9603140bed9d9a929e7890f5.png)

* **EaseInOutCubic:**

![](https://i.gyazo.com/5c6cdac4aad70af9997dfddf30ffeceb.png)

* **EaseInQuart:**

![](https://i.gyazo.com/d65a1a144bab00e652cc0b8a4ed291ba.png)

* **EaseOutQuart:**

![](https://i.gyazo.com/326c7c28e74f5f4dbd80f75fcd24d4f0.png)

* **EaseInOutQuart:**

![](https://i.gyazo.com/d3103d81ca39933d721342e6310f54be.png)

* **EaseInQuint:**

![](https://i.gyazo.com/48b969fa1b55001807d00b092466b784.png)

* **EaseOutQuint:**

![](https://i.gyazo.com/41f94cf4f39b093e55544fe9b7cff913.png)

* **EaseInOutQuint:**

![](https://i.gyazo.com/685e697bf802b1757eef22dc13ec5df8.png)

* **EaseInCirc:**

![](https://i.gyazo.com/7e93c2ba14629e87a5b72114953a7c36.png)

* **EaseOutCirc:**

![](https://i.gyazo.com/710f3136db37a72ef454bf14fb7f51a1.png)

* **EaseInOutCirc:**

![](https://i.gyazo.com/fba222d695cb019c58e497fd99744041.png)

* **EaseInExpo:**

![](https://i.gyazo.com/146977a727bacb15269c5802b65646f8.png)

* **EaseOutExpo:**

![](https://i.gyazo.com/7c57851bb9f8c2d2f6cd2fc8b48c9390.png)

* **EaseInOutExpo:**

![](https://i.gyazo.com/ef6fe06c75ce4d1a126e4ad3983a1d7f.png)

* **EaseInBack:**

![](https://i.gyazo.com/968321f2e6a47fa65e03e029f2309896.png)

* **EaseOutBack:**

![](https://i.gyazo.com/a4e188a4f409130b4883a1b19ddfb0e2.png)

* **EaseInOutBack:**

![](https://i.gyazo.com/ad80bc3b6f13a0358805ecd30fcefa94.png)


# Introduction to the code

In order to achieve my goal, I create a new module called EasingSplines. This module will manage all splines created.

Let's see its core code.


First of all, it has a struct called EaseSplineInfo, this struct contains all the variables that are needed to have a spline:

* **int * position:** A pointer to the position of the element we want to move, thanks to that, we can change that value because we have the adress.
* **int initial_position:** The initial value of the element.
* **int distance_to_travel:** The distance we want to travel.
* **float time_to_travel:** The time we want to do the spline requested.
* **float time_started:** The time when the spline started.
* **TypeSpline type:** The type of spline is it.
* **EaseFunctions ease_function:** A variable to a struct that contains all the spline functions.
* **bool Update(float dt):** Function in which the spline makes its update.

![](https://i.gyazo.com/019959c027b3ef39920dd4b0f3df4269.png)

Then, we have a struct that has all the easing functions in order to have all them in the same site.

![](https://i.gyazo.com/ff28bfd5167b023514f1474723de7096.png)

We have an enum of all the spline type that areable to be used:

![](https://i.gyazo.com/ee7dca1a740b7211cab2bfcc5855cd55.png)

Our module has a list with all the splines created that have not finished.

![](https://i.gyazo.com/7d454f80262ae758723d7e492f04e91a.png)

In the Update of the module, we use this list to call each Update of our splines. When a spline has finished, it returns false so we must delete it.

![](https://i.gyazo.com/f56f3a30a546747c15614bef82546b68.png)

Finally, we have our main function to create and add a new spline. This function needs 4 parameters (pointer to the value, the target value, the time to achive target value and the type of spline we want to use). 

![](https://i.gyazo.com/9d018749d2912b016a91b306f49528bd.png)

# TODOs
Click [here](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/releases) to download the TODOs. 

## TODO 1

Create the constructor of the struct:

![](https://i.gyazo.com/04136c6c6202186cda24626028492d21.png)

### Solution

![](https://i.gyazo.com/560dc9464133f4bfeb3ff3f48a6c2254.png)

## TODO 2

Calculate the time that has passed since the spline started. Save this value in a float.

![](https://i.gyazo.com/65ccfe4907d86316894798b6e8b59686.png)

### Solution

![](https://i.gyazo.com/665e3005e72522e36246e6c342c289eb.png)

## TODO 3

Think how can we know if a spline has finished or not using the time calculated before. 
If the splines has finished, Update must end with a false in order to delete it

![](https://i.gyazo.com/27b713abc8b11a3d896465f6f3aabb46.png)

### Solution

![](https://i.gyazo.com/522c944bd8979c042b9f6d7514da0a32.png)

## TODO 4

If the spline has not finished, make a switch with the spline type and call its type function. Look what this function returns! 

![](https://i.gyazo.com/ae3ad3cc63a7c2301c71bf219e0c7eec.png)

### Solution 

![](https://i.gyazo.com/0a9fa4eb0cacbbbefa75694ff2d9ca98.png)

## TODO 5

Look the function CreateSpline() from EasingSplines.cpp, then use it to create one.

![](https://i.gyazo.com/6500e9e32577cade81f5499ab48b1453.png)

### Solution

![](https://i.gyazo.com/1c75fcf0a09e07e471eef33b593611d2.png)

