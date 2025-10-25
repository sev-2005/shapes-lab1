#include "Shape2D.h"
#include <iostream>
#include <stdexcept>

Shape2D::Shape2D()
	: type(nullptr), dimensions(nullptr), area(0), drawing(nullptr)
{
	std::cout << "Shape2D: Default constructor called" << std::endl;
}

Shape2D::Shape2D(const char *shapeType, const char *dims, const char *draw)
{
	// Implementation will be in next commit
	type = new char[strlen(shapeType) + 1];
	strcpy(type, shapeType);

	dimensions = new char[strlen(dims) + 1];
	strcpy(dimensions, dims);

	if (draw)
	{
		drawing = new char[strlen(draw) + 1];
		strcpy(drawing, draw);
	}
	else
	{
		drawing = nullptr;
	}

	calculateArea();
	std::cout << "Shape2D: Parameterized constructor called for " << type << std::endl;
}

// Other methods will be implemented in next commits

void Shape2D::display() const
{
	std::cout << "2D Shape: " << type << std::endl;
}

void Shape2D::edit()
{
	// To be implemented
}

void Shape2D::saveToFile(std::ostream &os) const
{
	// To be implemented
}

void Shape2D::loadFromFile(std::istream &is)
{
	// To be implemented
}

void Shape2D::calculateArea()
{
	// To be implemented
}