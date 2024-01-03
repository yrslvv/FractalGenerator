# Fractal Generator

## Skills Covered
- **Complex Number Manipulation**: Handling mathematical operations with complex numbers.
- **Dynamic Memory Management**: Efficient use of pointers and dynamic allocation.
- **Object-Oriented Programming**: Utilization of classes and objects.
- **Operator Overloading**: Custom implementation for mathematical operations.
- **Fractal Generation Algorithms**: Implementing the Newton fractal generation logic.
- **Image Processing**: Saving fractals as PPM files.
- **Exception Handling**: Managing input errors and exceptions.
- **Pixel Color Manipulation**: Custom class for handling pixel data.

## Major Decisions
- Implementing a custom `Complex` class for complex number operations.
- Designing the `Pixel` class for managing pixel color data.
- Developing the `Fractal` class to generate and manipulate fractal images.
- Overloading operators in `Complex` and `Pixel` classes for intuitive usage.
- Utilizing dynamic memory allocation for managing the fractal grid.

## Features Implemented
- **Fractal Image Generation**: Creating fractal patterns based on 𝒇(𝒁𝒏) = 𝒁𝒏^3 − 2𝒁𝒏 + 2.
- **Colorful Fractal Representation**: Pixel manipulation to represent fractals vividly.
- **Memory Management**: Efficient creation and deletion of dynamic objects.
- **File Output**: Saving generated fractals as PPM files.
- **Exception Handling in Complex Numbers**: Robust error checking in complex number operations.

## Problems Identified
- Memory Management: Ensuring efficient allocation and deallocation of memory.
- Performance Optimization: Enhancing the speed of fractal generation.
- Color Dynamics: Improving the visual appeal of fractal images.
