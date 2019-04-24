# Easing and splines for cameras and UI
I am [Oriol Capdevila Salinas](https://www.linkedin.com/in/oriol-capdevila-0a6b3914b/), student of the [Bachelor’s Degree in Video Games by UPC at CITM](https://www.citm.upc.edu/). This content is made for the second year’s subject Project 2, under supervision of lecturer [Ricard Pillosu](https://www.linkedin.com/in/ricardpillosu?originalSubdomain=es).
# Problem & Solution
We have some problems when we have to move the camera or some UI because we had just one way to do it:

`App->render->camera.x -= 100*dt;`

And we had to put a condition in order to finish it when we wanted. This might be fine for simple games and simple camera movements, but how we could have done this movement with this system: (the speed decreases with time) 

![](https://im5.ezgif.com/tmp/ezgif-5-c1046f1efd98.gif)

It is not a difficult movement, but with our old system, this must have been hardcoded. So, my objective is that to make this movement and far more with just calling a function once, let's start.

![](https://i.gyazo.com/cbe1999d34d513cb9b89c1823d0b2a61.png)

# Introduction to Splines
In mathematics, a spline is a piecewise function defined by polynomials. This functions are usually used in programming because of the simplicity of their construction, their ease and accuracy of evaluation.  
