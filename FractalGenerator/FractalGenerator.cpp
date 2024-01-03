
#include <iostream>
#include "Fractal.h"
#include "Pixel.h"
#include "Complex.h"
using namespace std;

Fractal testMoveConstructor(unsigned int rows, unsigned int cols) noexcept {
    Fractal f(rows, cols);
    return f;
}
int main()
{

    Fractal m1(2000U, 2000U), m2, m3;
    saveToPPM(m1, "newton1.ppm");
    m2 = Fractal(m1);
    saveToPPM(m2, "newton2.ppm");
    m3 = testMoveConstructor(600U, 800U);
    saveToPPM(m3, "newton3.ppm");

    return 0;
}
