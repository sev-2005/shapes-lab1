#include "Shape2D.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

class ShapeException : public std::exception
{
private:
	char *message;

public:
	ShapeException(const char *msg)
	{
		message = new char[strlen(msg) + 1];
		strcpy(message, msg);
	}
	~ShapeException() { delete[] message; }
	const char *what() const noexcept override { return message; }
};

Shape2D::Shape2D()
	: type(nullptr), dimensions(nullptr), area(0), drawing(nullptr)
{
	std::cout << "Shape2D: Default constructor called" << std::endl;
}

Shape2D::Shape2D(const char *shapeType, const char *dims)
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

	calculateArea();
	generateDrawing();

	std::cout << "Shape2D: Parameterized constructor called for " << type << std::endl;
}

Shape2D::Shape2D(const Shape2D &other)
{
	type = new char[strlen(other.type) + 1];
	strcpy(type, other.type);

	dimensions = new char[strlen(other.dimensions) + 1];
	strcpy(dimensions, other.dimensions);

	area = other.area;

	if (other.drawing)
	{
		drawing = new char[strlen(other.drawing) + 1];
		strcpy(drawing, other.drawing);
	}
	else
	{
		drawing = nullptr;
	}

	std::cout << "Shape2D: Copy constructor called for " << type << std::endl;
}

Shape2D::~Shape2D()
{
	delete[] type;
	delete[] dimensions;
	delete[] drawing;
	std::cout << "Shape2D: Destructor called for " << (type ? type : "unknown") << std::endl;
}

Shape2D &Shape2D::operator=(const Shape2D &other)
{
	if (this != &other)
	{
		delete[] type;
		delete[] dimensions;
		delete[] drawing;

		type = new char[strlen(other.type) + 1];
		strcpy(type, other.type);

		dimensions = new char[strlen(other.dimensions) + 1];
		strcpy(dimensions, other.dimensions);

		area = other.area;

		if (other.drawing)
		{
			drawing = new char[strlen(other.drawing) + 1];
			strcpy(drawing, other.drawing);
		}
		else
		{
			drawing = nullptr;
		}
	}
	std::cout << "Shape2D: Assignment operator called for " << type << std::endl;
	return *this;
}

void Shape2D::calculateArea()
{
	if (strcmp(type, "Circle") == 0)
	{
		double radius;
		if (sscanf(dimensions, "Radius: %lf", &radius) == 1)
		{
			area = 3.14159 * radius * radius;
		}
	}
	else if (strcmp(type, "Rectangle") == 0)
	{
		double width, height;
		if (sscanf(dimensions, "Width: %lf, Height: %lf", &width, &height) == 2)
		{
			area = width * height;
		}
	}
	else if (strcmp(type, "Triangle") == 0)
	{
		double base, height;
		if (sscanf(dimensions, "Base: %lf, Height: %lf", &base, &height) == 2)
		{
			area = 0.5 * base * height;
		}
	}
}

void Shape2D::generateDrawing()
{
	if (strcmp(type, "Circle") == 0)
	{
		const char *circle =
			"  ***  \n"
			" *   * \n"
			"*     *\n"
			" *   * \n"
			"  ***  \n";
		drawing = new char[strlen(circle) + 1];
		strcpy(drawing, circle);
	}
	else if (strcmp(type, "Rectangle") == 0)
	{
		const char *rect =
			"*******\n"
			"*     *\n"
			"*     *\n"
			"*******\n";
		drawing = new char[strlen(rect) + 1];
		strcpy(drawing, rect);
	}
	else if (strcmp(type, "Triangle") == 0)
	{
		const char *triangle =
			"   *   \n"
			"  * *  \n"
			" *   * \n"
			"*******\n";
		drawing = new char[strlen(triangle) + 1];
		strcpy(drawing, triangle);
	}
}

void Shape2D::setType(const char *shapeType)
{
	if (!shapeType || strlen(shapeType) == 0)
	{
		throw ShapeException("Shape type cannot be empty");
	}
	delete[] type;
	type = new char[strlen(shapeType) + 1];
	strcpy(type, shapeType);
	calculateArea();
	generateDrawing();
}

void Shape2D::setDimensions(const char *dims)
{
	if (!dims || strlen(dims) == 0)
	{
		throw ShapeException("Dimensions cannot be empty");
	}
	delete[] dimensions;
	dimensions = new char[strlen(dims) + 1];
	strcpy(dimensions, dims);
	calculateArea();
	generateDrawing();
}

void Shape2D::display() const
{
	std::cout << "\n=== 2D Shape ===" << std::endl;
	std::cout << "Type: " << type << std::endl;
	std::cout << "Dimensions: " << dimensions << std::endl;
	std::cout << "Area: " << area << std::endl;
	if (drawing)
	{
		std::cout << "Drawing:\n"
				  << drawing << std::endl;
	}
}

void Shape2D::edit()
{
	std::cout << "\n=== Editing " << type << " ===" << std::endl;

	char buffer[100];
	std::cout << "Enter new type (current: " << type << "): ";
	std::cin.getline(buffer, 100);
	if (strlen(buffer) > 0)
	{
		setType(buffer);
	}

	std::cout << "Enter new dimensions (current: " << dimensions << "): ";
	std::cin.getline(buffer, 100);
	if (strlen(buffer) > 0)
	{
		setDimensions(buffer);
	}
}

void Shape2D::saveToFile(std::ostream &os) const
{
	os << "2D\n";
	os << type << "\n";
	os << dimensions << "\n";
	os << area << "\n";
}

void Shape2D::loadFromFile(std::istream &is)
{
	char buffer[100];

	is.getline(buffer, 100); // skip "2D"
	is.getline(buffer, 100);
	setType(buffer);

	is.getline(buffer, 100);
	setDimensions(buffer);

	is >> area;
	is.ignore();
}