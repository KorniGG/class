#pragma once
#include <iostream>
#include <cmath> 

struct Fraction 
{
    double first;
    double second;
    void Init(double, double);
    void Read(); 
    void Show() const; 
    double Hipotenuza();
};
