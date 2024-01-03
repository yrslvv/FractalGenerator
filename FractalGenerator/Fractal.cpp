#include <cmath>
#include <fstream>
#include "Fractal.h"
#include "Complex.h"

unsigned int Fractal::maxIter = 30;

Fractal::~Fractal()
{
	std::cout << "Destructor called." << std::endl;
	for (int i = 0; i < rows; i++) {
		delete[] grid[i];
	}
	delete[] grid;
}



Fractal::Fractal()
{
	std::cout << "Default constructor called." << std::endl;
	grid == nullptr;
	cols = 0;
	rows = 0;
}

Fractal::Fractal(const Fractal& f)
{
	std::cout << "Copy constructor called." << std::endl;
	cols = f.cols;
	rows = f.rows;
	grid = new Pixel * [rows];
	for (unsigned int i = 0; i < rows; i++) {
		grid[i] = new Pixel[cols];
	}
	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < cols; j++) {
			grid[i][j] = f.grid[i][j];
		}
	}
}

Fractal::Fractal(Fractal&& f) noexcept
{
	std::cout << "Move constructor called." << std::endl;
	grid = f.grid;
	cols = f.cols;
	rows = f.rows;
	f.grid = nullptr;
	f.cols = 0;
	f.rows = 0;

}

Fractal::Fractal(unsigned int cols, unsigned int rows)
{
	std::cout << "Two-arg constructor called." << std::endl;
	this->cols = cols;
	this->rows = rows;
	grid = new Pixel * [rows];
	for (int i = 0; i < rows; i++)
		grid[i] = new Pixel[cols];
	std::cout << "Now creating the Newton Fractal...\n";
	(*this).makeNewtonFractal();
}


void Fractal::makeNewtonFractal()
{
	Complex Z;
	double step_height = 4.0 / rows;
	double step_width = 4.0 / cols;
	for (unsigned int j = 0; j < rows; j++)
	{
		for (unsigned int k = 0; k < cols; k++)
		{
			Z["imag"] = 2.0 - (j * step_height);
			Z["real"] = (k * step_width) - 2.0;
			grid[j][k] = determinePixelColor(Z);
		}
	}

}
Pixel Fractal::determinePixelColor(Complex Z)
{
	double tol = 1E-4, diff = 1.0, test = 0.58974;
	unsigned int iter = 0, color = 0;
	Complex Znew;

	while (iter < 512)
	{
		iter++;
		Znew = Z - ((Z * Z * Z) - (2.0 * Z) + 2.0) / ((3.0 * Z * Z) - 2.0);
		diff = getMagnitude(Z - Znew);
		Z = Znew;
		if (diff < tol)
		{
			color = maxIter - std::min(iter, maxIter);
			if (abs(Z["imag"]) < tol)
				return Pixel(color, color, 0);
			else if (abs(Z["imag"] - test) < tol)
				return Pixel(0, color, color);
			else if (abs(Z["imag"] + test) < tol)
				return Pixel(color, 0, color);
		}
	}
	return Pixel(0, 0, 0);
}

const Fractal& Fractal::operator=(const Fractal& f) noexcept
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &f) {
		for (unsigned int i = 0; i < rows; i++) {
			delete[] grid[i];
		}
		delete[] grid;
		rows = f.rows;
		cols = f.cols;
		grid = new Pixel * [rows];
		for (unsigned int i = 0; i < rows; i++) {
			grid[i] = new Pixel[cols];
		}
		for (unsigned int i = 0; i < f.rows; i++) {
			for (unsigned j = 0; j < f.cols; j++) {
				grid[i][j] = f.grid[i][j];
			}
		}
	}
	return *this;

}

Fractal& Fractal::operator=(Fractal&& right) noexcept
{
	std::cout << "Move Assignment operator called." << std::endl;
	if (this != &right) {
		std::swap(grid, right.grid);
		std::swap(cols, right.cols);
		std::swap(rows, right.rows);
	}
	return *this;
}



void saveToPPM(Fractal& f, std::string fileName)
{
	std::fstream out(fileName, std::ios::out);
	if (out) {
		out << "P3\n" << f.cols << " " << f.rows << "\n" << f.maxIter << std::endl;
		for (int i = 0; i < f.rows; i++) {
			for (int j = 0; j < f.cols; j++) {
				out << f.grid[i][j] << "  ";
			}
			out << std::endl;
		}
	}
	out.close();
	std::cout << "Saving Fractal object to PPM file." << std::endl;
}