#pragma once
#include "Complex.h"
#include "Pixel.h"
class Fractal
{
private:
	unsigned int cols;
	Pixel** grid;
	static unsigned int maxIter;
	unsigned int rows;

	Pixel determinePixelColor(Complex);
	void makeNewtonFractal();
public:
	~Fractal();
	Fractal();
	Fractal(const Fractal&);
	Fractal(Fractal&&) noexcept;
	Fractal(unsigned int, unsigned int);
	const Fractal& operator=(const Fractal&) noexcept;
	Fractal& operator=(Fractal&&) noexcept;
	friend void saveToPPM(Fractal& f, std::string fileName);
};
