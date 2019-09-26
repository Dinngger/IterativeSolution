/*
 * IterativeSolution.hpp
 * 
 * Created Date: Friday, September 20th 2019, 1:27:17 pm
 * by Dinger
 */
#ifndef __ITERATIVE_SOLUTION_HPP
#define __ITERATIVE_SOLUTION_HPP

#include <iostream>
#define abs(x) ((x) >= 0 ? (x) : -(x))

template <typename T>
class IterativeSolution
{
protected:
    T targetErr;
    T (*func) (T);
public:
    T x, Err;
    IterativeSolution(const T &x0, const T &targetErr) :
        targetErr(targetErr),
        x(x0) {}
    IterativeSolution(const T &x0, const T &targetErr, T (*func) (T)) :
        targetErr(targetErr),
        func(func),
        x(x0) {}
    ~IterativeSolution() {}
    virtual T iterate() = 0;
};

template <typename T>
class NewtonMethod : public IterativeSolution <T>
{
private:
    T (*dFunc) (T);
public:
    NewtonMethod(T x0, T targetErr, T (*func) (T), T (*dFunc) (T)) :
        IterativeSolution<T>::IterativeSolution(x0, targetErr, func),
        dFunc(dFunc) {}
    ~NewtonMethod() {}
    virtual T iterate() override;
};

template <typename T>
T NewtonMethod<T>::iterate()
{
    do {
        this->Err = - this->func(this->x) / (this->dFunc(this->x) + 1e-10);
        this->x += this->Err;
        std::cout << "x: " << this->x << " Err: " << this->Err << std::endl;
    } while (abs(this->Err) > abs(this->targetErr));
    return this->x;
}

template <typename T>
struct Pair
{
    T a;
    T b;
    Pair() {}
    Pair(const T &a, const T &b) : a(a), b(b) {}
};

template <typename T>
class SecantMethod : public IterativeSolution <Pair<T>>
{
    using PT = Pair <T>;
private:
    T (*TFunc) (T);
public:
    SecantMethod(T x0, T x1, T targetErr, T (*func) (T)) :
        IterativeSolution<PT>::IterativeSolution(PT(x0, x1), PT(targetErr, targetErr)),
        TFunc(func) {}
    ~SecantMethod() {}
    virtual PT iterate() override;
};

template <typename T>
Pair<T> SecantMethod<T>::iterate()
{
    T y0 = this->TFunc(this->x.a);
    do {
        T y1 = this->TFunc(this->x.b);
        T x2 = (y0 * this->x.b - y1 * this->x.a) / (y0 - y1 + 1e-10);
        this->x = PT(this->x.b, x2);
        y0 = y1;
        this->Err.a = x2 - this->x.a;
        std::cout << "x: " << x2 << " Err: " << this->Err.a << std::endl;
    } while (abs(this->Err.a) > abs(this->targetErr.a));
    return this->x;
}

#endif
