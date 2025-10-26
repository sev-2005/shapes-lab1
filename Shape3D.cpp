#include "Shape3D.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

Shape3D::Shape3D()
	: type(nullptr), dimensions(nullptr), volume(0), drawing2D(nullptr)
{
	std::cout << "Shape3D: Default constructor called" << std::endl;
}

Shape3D::Shape3D(const char *shapeType, const char *dims)
{
	if (!shapeType || strlen(shapeType) == 0)
	{
		throw ShapeException("Shape type cannot be empty");
	}

	type = new char[strlen(shapeType) + 1];
	strcpy(type, shapeType);

	if (!dims || strlen(dims) == 0)
	{
		throw ShapeException("Dimensions cannot be empty");
	}
	dimensions = new char[strlen(dims) + 1];
	strcpy(dimensions, dims);

	calculateVolume();
	generateDrawing2D();

	std::cout << "Shape3D: Parameterized constructor called for " << type << std::endl;
}

// ... (реализация остальных методов аналогично Shape2D, но для 3D фигур)

void Shape3D::calculateVolume()
{
	if (strcmp(type, "Cube") == 0)
	{
		double side;
		if (sscanf(dimensions, "Side: %lf", &side) == 1)
		{
			volume = side * side * side;
		}
	}
	else if (strcmp(type, "Sphere") == 0)
	{
		double radius;
		if (sscanf(dimensions, "Radius: %lf", &radius) == 1)
		{
			volume = (4.0 / 3.0) * 3.14159 * radius * radius * radius;
		}
	}
	else if (strcmp(type, "Cylinder") == 0)
	{
		double radius, height;
		if (sscanf(dimensions, "Radius: %lf, Height: %lf", &radius, &height) == 2)
		{
			volume = 3.14159 * radius * radius * height;
		}
	}
}

void Shape3D::generateDrawing2D()
{
	if (strcmp(type, "Cube") == 0)
	{
		const char *cube =
			"  +----+\n"
			" /    /|\n"
			"+----+ |\n"
			"|    | +\n"
			"|    |/\n"
			"+----+\n";
		drawing2D = new char[strlen(cube) + 1];
		strcpy(drawing2D, cube);
	}
	else if (strcmp(type, "Sphere") == 0)
	{
		const char *sphere =
			"   ***   \n"
			" *     * \n"
			"*       *\n"
			" *     * \n"
			"   ***   \n";
		drawing2D = new char[strlen(sphere) + 1];
		strcpy(drawing2D, sphere);
	}
}

void Shape3D::display() const
{
	std::cout << "\n=== 3D Shape ===" << std::endl;
	std::cout << "Type: " << type << std::endl;
	std::cout << "Dimensions: " << dimensions << std::endl;
	std::cout << "Volume: " << volume << std::endl;
	if (drawing2D)
	{
		std::cout << "2D Projection:\n"
				  << drawing2D << std::endl;
	}
}