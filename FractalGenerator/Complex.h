#pragma once
#include <cmath>


class Complex
{
private:
	double imag;
	double real;
public:
	~Complex();
	Complex();
	Complex(const Complex&);
	Complex(double); // creates double value to a complex value
	Complex(double, double);
	double& operator[](const char*);
	friend const Complex operator*(const Complex&, const Complex&);
	friend const Complex operator/(const Complex&, const Complex&);
	friend const Complex operator+(const Complex&, const Complex&);
	friend const Complex operator-(const Complex&, const Complex&);
	friend double getMagnitude(const Complex&);

	class InputOutOfBoundsException
	{
	private:
		const char* errorMessage;
		const char* offendingIndex;
	public:
		InputOutOfBoundsException(const char*, const char*);
		const char* returnError();
		const char* returnOffendingIndex();
	};
};