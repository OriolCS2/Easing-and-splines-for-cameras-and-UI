# Easing and splines for cameras and UI
I am [Oriol Capdevila Salinas](https://www.linkedin.com/in/oriol-capdevila-0a6b3914b/), student of the [Bachelor’s Degree in Video Games by UPC at CITM](https://www.citm.upc.edu/). This content is made for the second year’s subject Project 2, under supervision of lecturer [Ricard Pillosu](https://www.linkedin.com/in/ricardpillosu?originalSubdomain=es).
# Problem & Solution
We have some problems when we have to move the camera or some UI because we had just one way to do it:

`App->render->camera.x -= 100*dt;`

And we had to put a condition in order to finish it when we wanted. This might be fine for simple games and simple camera movements, but how could we have done this movement with this system: (the speed decreases with time) 

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

Using differents math methods:



