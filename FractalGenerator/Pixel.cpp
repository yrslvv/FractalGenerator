#include "Pixel.h"

Pixel::InputOutOfBoundsException::InputOutOfBoundsException(const char* err, const char* ind) : errorMessage(err), offendingIndex(ind) {}
const char* Pixel::InputOutOfBoundsException::returnError() { return errorMessage; }
const char* Pixel::InputOutOfBoundsException::returnOffendingIndex() { return offendingIndex; }

Pixel::~Pixel() {}

const unsigned int& Pixel::operator[](const char* n) const
{
	if (n == "red")
		return red;
	else if (n == "green")
		return green;
	else if (n == "blue")
		return blue;
	else
		throw InputOutOfBoundsException("ERROR! Wrong Pixel color name.", "Line 18");
}

Pixel::Pixel()
{
	red = 0;
	green = 0;
	blue = 0;
}

Pixel::Pixel(const Pixel& p)
{
	red = p["red"];
	green = p["green"];
	blue = p["blue"];
}

Pixel::Pixel(unsigned int r, unsigned int g, unsigned int b) : red{ r }, green{ g }, blue{ b } {};


std::ostream& operator<<(std::ostream& out, const Pixel& p)
{
	try {
		out << p["red"] << " " << p["green"] << " " << p["blue"];
	}
	catch (Pixel::InputOutOfBoundsException& a) {
		std::cout << a.returnError() << a.returnOffendingIndex() << std::endl;
		exit(1);
	}
	return out;

}