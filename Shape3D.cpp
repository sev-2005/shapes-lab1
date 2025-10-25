#include "Shape3D.h"
#include <iostream>
#include <stdexcept>

Shape3D::Shape3D()
	: type(nullptr), dimensions(nullptr), volume(0), drawing2D(nullptr)
{
	std::cout << "Shape3D: Default constructor called" << std::endl;
}

Shape3D::Shape3D(const char *shapeType, const char *dims, const char *draw2D)
{
	// Implementation will be in next commit
	type = new char[strlen(shapeType) + 1];
	strcpy(type, shapeType);

	dimensions = new char[strlen(dims) + 1];
	strcpy(dimensions, dims);

	if (draw2D)
	{
		drawing2D = new char[strlen(draw2D) + 1];
		strcpy(drawing2D, draw2D);
	}
	else
	{
		drawing2D = nullptr;
	}

	calculateVolume();
	std::cout << "Shape3D: Parameterized constructor called for " << type << std::endl;
}

// Other methods will be implemented in next commits

void Shape3D::display() const
{
	std::cout << "3D Shape: " << type << std::endl;
}

void Shape3D::edit()
{
	// To be implemented
}

void Shape3D::saveToFile(std::ostream &os) const
{
	// To be implemented
}

void Shape3D::loadFromFile(std::istream &is)
{
	// To be implemented
}

void Shape3D::calculateVolume()
{
	// To be implemented
}