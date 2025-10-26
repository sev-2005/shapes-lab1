#include "Shape3D.h"
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

Shape3D::Shape3D()
	: type(nullptr), dimensions(nullptr), volume(0), drawing2D(nullptr)
{
	std::cout << "Shape3D: Вызван конструктор по умолчанию" << std::endl;
}

Shape3D::Shape3D(const char *shapeType, const char *dims)
{
	if (!shapeType || strlen(shapeType) == 0)
	{
		throw ShapeException("Тип фигуры не может быть пустым");
	}

	type = new char[strlen(shapeType) + 1];
	strcpy(type, shapeType);

	if (!dims || strlen(dims) == 0)
	{
		throw ShapeException("Размеры не могут быть пустыми");
	}
	dimensions = new char[strlen(dims) + 1];
	strcpy(dimensions, dims);

	calculateVolume();
	generateDrawing2D();

	std::cout << "Shape3D: Вызван параметризованный конструктор для " << type << std::endl;
}

Shape3D::Shape3D(const Shape3D &other)
{
	type = new char[strlen(other.type) + 1];
	strcpy(type, other.type);

	dimensions = new char[strlen(other.dimensions) + 1];
	strcpy(dimensions, other.dimensions);

	volume = other.volume;

	if (other.drawing2D)
	{
		drawing2D = new char[strlen(other.drawing2D) + 1];
		strcpy(drawing2D, other.drawing2D);
	}
	else
	{
		drawing2D = nullptr;
	}

	std::cout << "Shape3D: Вызван конструктор копирования для " << type << std::endl;
}

Shape3D::~Shape3D()
{
	delete[] type;
	delete[] dimensions;
	delete[] drawing2D;
	std::cout << "Shape3D: Вызван деструктор для " << (type ? type : "неизвестно") << std::endl;
}

Shape3D &Shape3D::operator=(const Shape3D &other)
{
	if (this != &other)
	{
		delete[] type;
		delete[] dimensions;
		delete[] drawing2D;

		type = new char[strlen(other.type) + 1];
		strcpy(type, other.type);

		dimensions = new char[strlen(other.dimensions) + 1];
		strcpy(dimensions, other.dimensions);

		volume = other.volume;

		if (other.drawing2D)
		{
			drawing2D = new char[strlen(other.drawing2D) + 1];
			strcpy(drawing2D, other.drawing2D);
		}
		else
		{
			drawing2D = nullptr;
		}
	}
	std::cout << "Shape3D: Вызван оператор присваивания для " << type << std::endl;
	return *this;
}

void Shape3D::calculateVolume()
{
	if (strcmp(type, "Куб") == 0)
	{
		double side;
		if (sscanf(dimensions, "Сторона: %lf", &side) == 1)
		{
			volume = side * side * side;
		}
	}
	else if (strcmp(type, "Сфера") == 0)
	{
		double radius;
		if (sscanf(dimensions, "Радиус: %lf", &radius) == 1)
		{
			volume = (4.0 / 3.0) * 3.14159 * radius * radius * radius;
		}
	}
	else if (strcmp(type, "Цилиндр") == 0)
	{
		double radius, height;
		if (sscanf(dimensions, "Радиус: %lf, Высота: %lf", &radius, &height) == 2)
		{
			volume = 3.14159 * radius * radius * height;
		}
	}
}

void Shape3D::generateDrawing2D()
{
	if (strcmp(type, "Куб") == 0)
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
	else if (strcmp(type, "Сфера") == 0)
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
	else if (strcmp(type, "Цилиндр") == 0)
	{
		const char *cylinder =
			"  *****  \n"
			" *     * \n"
			"*       *\n"
			"*       *\n"
			" *     * \n"
			"  *****  \n";
		drawing2D = new char[strlen(cylinder) + 1];
		strcpy(drawing2D, cylinder);
	}
}

void Shape3D::setType(const char *shapeType)
{
	if (!shapeType || strlen(shapeType) == 0)
	{
		throw ShapeException("Тип фигуры не может быть пустым");
	}
	delete[] type;
	type = new char[strlen(shapeType) + 1];
	strcpy(type, shapeType);
	calculateVolume();
	generateDrawing2D();
}

void Shape3D::setDimensions(const char *dims)
{
	if (!dims || strlen(dims) == 0)
	{
		throw ShapeException("Размеры не могут быть пустыми");
	}
	delete[] dimensions;
	dimensions = new char[strlen(dims) + 1];
	strcpy(dimensions, dims);
	calculateVolume();
	generateDrawing2D();
}

void Shape3D::display() const
{
	std::cout << "\n=== 3D Фигура ===" << std::endl;
	std::cout << "Тип: " << type << std::endl;
	std::cout << "Размеры: " << dimensions << std::endl;
	std::cout << "Объем: " << volume << std::endl;
	if (drawing2D)
	{
		std::cout << "2D Проекция:\n"
				  << drawing2D << std::endl;
	}
}

void Shape3D::edit()
{
	std::cout << "\n=== Редактирование " << type << " ===" << std::endl;

	char buffer[100];
	std::cout << "Введите новый тип (текущий: " << type << "): ";
	std::cin.getline(buffer, 100);
	if (strlen(buffer) > 0)
	{
		setType(buffer);
	}

	std::cout << "Введите новые размеры (текущие: " << dimensions << "): ";
	std::cin.getline(buffer, 100);
	if (strlen(buffer) > 0)
	{
		setDimensions(buffer);
	}
}

void Shape3D::saveToFile(std::ostream &os) const
{
	os << "3D\n";
	os << type << "\n";
	os << dimensions << "\n";
	os << volume << "\n";
}

void Shape3D::loadFromFile(std::istream &is)
{
	char buffer[100];

	is.getline(buffer, 100); // пропускаем "3D"
	is.getline(buffer, 100);
	setType(buffer);

	is.getline(buffer, 100);
	setDimensions(buffer);

	is >> volume;
	is.ignore();
}