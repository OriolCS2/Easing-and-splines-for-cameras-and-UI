# Easing and splines for cameras and UI
I am [Oriol Capdevila Salinas](https://www.linkedin.com/in/oriol-capdevila-0a6b3914b/), student of the [Bachelor’s Degree in Video Games by UPC at CITM](https://www.citm.upc.edu/). This content is made for the second year’s subject Project 2, under supervision of lecturer [Ricard Pillosu](https://www.linkedin.com/in/ricardpillosu?originalSubdomain=es).

Click [here](https://docs.google.com/presentation/d/1UyswfESDVSMCwxbRJeeEHeANahBYPCxUrXUZrsLFn08/edit?usp=sharing) to see the presentation.
# Problem & Solution
We have some problems when we have to move the camera or some UI because we just had one way to do it:

`App->render->camera.x -= 100*dt;`

We had to put a condition in order to finish it when we wanted. This might be fine for simple games and simple camera movements, but how could we have done this movement with this system: (the speed decreases with time) 

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/gifs/cubic.gif)

It is not a difficult movement, but with our old system, this must have been hardcoded. So, my objective is that to make this movement and far more with just calling a function once, let's start.

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/cbe1999d34d513cb9b89c1823d0b2a61.png?raw=true)

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

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/gifs/linear.gif)

* **Quad:** Power of 2.

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/gifs/quad.gif)

* **Cubic:** Power of 3.

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/gifs/cubic.gif)

* **Quart:** Power of 4.

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/gifs/quart.gif)

* **Quint:** Power of 5.

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/gifs/quint.gif)

* **Circ:** Power of 6.

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/gifs/circ.gif)

Some others that use differents math methods:

* **Back:** The object bypass the objective and then returns.

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/gifs/back.gif)

* **Expo:** Increases/decreases exponentially the initial value.

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/gifs/expo.gif)

Each ease function, less the linear, has three different functions:

* **Ease In:** Describe the positive acceleration of the element that is being moved.
* **Ease Out:** Describe the negative acceleration of the element that is being moved.
* **Ease In Out:** It is a combination of the two movements described above, first Ease In and the Ease Out. 

## Graphic Help of each Function

* **EaseInQuad:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeinquad.png?raw=true)

* **EaseOutQuad:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeOutQUad.png?raw=true)

* **EaseInOutQuad:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeinoutQuad.png?raw=true)

* **EaseInCubic:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeincubic.png?raw=true)

* **EaseOutCubic:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeoutcubic.png?raw=true)

* **EaseInOutCubic:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeinoutcubic.png?raw=true)

* **EaseInQuart:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeinquart.png?raw=true)

* **EaseOutQuart:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeoutquart.png?raw=true)

* **EaseInOutQuart:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeinoutquart.png?raw=true)

* **EaseInQuint:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeinquint.png?raw=true)

* **EaseOutQuint:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeoutquint.png?raw=true)

* **EaseInOutQuint:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeinoutquint.png?raw=true)

* **EaseInCirc:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeincirc.png?raw=true)

* **EaseOutCirc:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeoutcirc.png?raw=true)

* **EaseInOutCirc:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeinoutcirc.png?raw=true)

* **EaseInExpo:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeinexpo.png?raw=true)

* **EaseOutExpo:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeoutexpo.png?raw=true)

* **EaseInOutExpo:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeinoutexpo.png?raw=true)

* **EaseInBack:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeinback.png?raw=true)

* **EaseOutBack:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeoutback.png?raw=true)

* **EaseInOutBack:**

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/easeinoutback.png?raw=true)


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

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/structspline.png?raw=true)

Then, we have a struct that has all the easing functions in order to have all them in the same site.

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/structsplinefunctions.png?raw=true)

We have an enum of all the spline type that areable to be used:

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/enumsplines.png?raw=true)

Our module has a list with all the splines created that have not finished.

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/listsplines.png?raw=true)

In the Update of the module, we use this list to call each Update of our splines. When a spline has finished, it returns false so we must delete it.

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/updatemodule.png?raw=true)

Finally, we have our main function to create and add a new spline. This function needs 4 parameters (pointer to the value, the target value, the time to achive target value and the type of spline we want to use). 

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/createspline.png?raw=true)

# TODOs

Click [here](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/releases/tag/0.0) to download the full code.

Click [here](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/releases/tag/1.0) to download the release. 

## TODO 1

Create the constructor of the struct:

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/todo1.png?raw=true)

### Solution

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/todo1solution.png?raw=true)

## TODO 2

Calculate the time that has passed since the spline started. Save this value in a float.

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/todo2.png?raw=true)

### Solution

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/todo2solution.png?raw=true)

## TODO 3

Think how can we know if a spline has finished or not using the time calculated before. 
If the splines has finished, Update must end with a false in order to delete it

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/todo3.png?raw=true)

### Solution

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/todo3solution.png?raw=true)

## TODO 4

If the spline has not finished, make a switch with the spline type and call its type function. Look what this function returns! 

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/todo4.png?raw=true)

### Solution 

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/todo4solution.png?raw=true)

## TODO 5

Look the function CreateSpline() from EasingSplines.cpp, then use it to create one.

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/todo5.png?raw=true)

### Solution

![](https://github.com/OriolCS2/Easing-and-splines-for-cameras-and-UI/blob/master/docs/images/todo5solution.png?raw=true)

# Improvements

* With this system, if we wanted to move the camera in X and Y at the same time we must create 2 splines. So it would be a great improvement to make it allow two values.
* Splines work with float, so we lose precision because the system works with int. 

# Author

**Oriol Capdevila Salinas**
  * [GitHub Account](https://github.com/OriolCS2/)
  * oriolcapdevilas@hotmail.com

