#pragma once
#include <iostream>

class Pixel
{
public:
	unsigned int red;
	unsigned int green;
	unsigned int blue;
public:
	~Pixel();
	const unsigned int& operator[](const char*) const;
	Pixel();
	Pixel(const Pixel&);
	Pixel(unsigned int, unsigned int, unsigned int);
	friend std::ostream& operator<<(std::ostream& out, const Pixel& p);

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
