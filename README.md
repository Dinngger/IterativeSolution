# Iterative Solution
This program uses two ways of iterative solution to solve function $f(x) = 0$.
The Newton Method is faster but needs derivative function while the Secant Method is a little slower but easier.

## Method
## 1. The Newton Method
$$x_k = x_{k-1} - \frac {f(x_{k-1})} {f'(x_{k-1})} $$

## 2. The Secant Method
$$x_k = \frac {x_0 {f(x_1)} - x_1 {f(x_0)}} {f(x_1) - f(x_0)}$$

## How to use
First create the object:

    MethodName<x_typename> NewtonSolution(x0, target_error, the_function, derivative_func);

Then call the iterate() method:

    NewtonSolution.iterate();

Look 'IterativeSolutionTest.cpp' file for examples.

## Add more method

Generate the IterativeSolution class and change the method.
