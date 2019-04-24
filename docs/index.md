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
