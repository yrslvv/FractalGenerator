#include "Complex.h"
#include <iostream>
using namespace std;
Complex::~Complex() {}

Complex::Complex() { imag = real = 0; }

Complex::Complex(const Complex& num)
{
    imag = num.imag;
    real = num.real;
}

Complex::Complex(double n)
{
    real = n;
    imag = 0;
}

Complex::Complex(double real, double imag) :real{ real }, imag{ imag } {};

double& Complex::operator[](const char* ind)
{
    if (ind == "real")
        return real;
    else if (ind == "imag")
        return imag;
    else
        throw InputOutOfBoundsException("ERROR! Invalid Expression.", "Line 29");
}



Complex::InputOutOfBoundsException::InputOutOfBoundsException(const char* err, const char* ind) : errorMessage(err), offendingIndex(ind) {}
const char* Complex::InputOutOfBoundsException::returnError() { return errorMessage; }
const char* Complex::InputOutOfBoundsException::returnOffendingIndex() { return offendingIndex; }

const Complex operator*(const Complex& c1, const Complex& c2)
{
    return Complex(c1.real * c2.real - c1.imag * c2.imag, c1.real * c2.imag + c1.imag * c2.real);
}

const Complex operator/(const Complex& c1, const Complex& c2)
{
    double realPart = (c1.real * c2.real + c1.imag * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
    double imagPart = (c1.imag * c2.real - c1.real * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
    return Complex(realPart, imagPart);
}

const Complex operator+(const Complex& c1, const Complex& c2)
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

const Complex operator-(const Complex& c1, const Complex& c2)
{
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

double getMagnitude(const Complex& f)
{
    return sqrt(f.real * f.real + f.imag * f.imag);
}