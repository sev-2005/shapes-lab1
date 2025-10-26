#include <iostream>
#include <limits>
#include <cstring>
#include "Keeper.h"
#include "Shape2D.h"
#include "Shape3D.h"

void displayMainMenu()
{
	std::cout << "\n=== Система управления геометрическими фигурами ===" << std::endl;
	std::cout << "1. Добавить 2D фигуру" << std::endl;
	std::cout << "2. Добавить 3D фигуру" << std::endl;
	std::cout << "3. Показать все фигуры" << std::endl;
	std::cout << "4. Редактировать фигуру" << std::endl;
	std::cout << "5. Удалить фигуру" << std::endl;
	std::cout << "6. Сохранить в файл" << std::endl;
	std::cout << "7. Загрузить из файла" << std::endl;
	std::cout << "0. Выход" << std::endl;
	std::cout << "Выберите опцию: ";
}

void display2DShapesMenu()
{
	std::cout << "\n=== Доступные 2D фигуры ===" << std::endl;
	std::cout << "1. Круг" << std::endl;
	std::cout << "2. Прямоугольник" << std::endl;
	std::cout << "3. Треугольник" << std::endl;
	std::cout << "Выберите тип фигуры: ";
}

void display3DShapesMenu()
{
	std::cout << "\n=== Доступные 3D фигуры ===" << std::endl;
	std::cout << "1. Куб" << std::endl;
	std::cout << "2. Сфера" << std::endl;
	std::cout << "3. Цилиндр" << std::endl;
	std::cout << "Выберите тип фигуры: ";
}

void addCircle(Keeper &keeper)
{
	std::cout << "\n=== Добавление круга ===" << std::endl;
	double radius;
	std::cout << "Введите радиус круга: ";
	std::cin >> radius;
	std::cin.ignore();

	char dimensions[50];
	sprintf(dimensions, "Радиус: %.2lf", radius);

	try
	{
		Shape2D *shape = new Shape2D("Круг", dimensions);
		keeper.add(shape);
		std::cout << "Круг успешно добавлен!" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Ошибка: " << e.what() << std::endl;
	}
}

void addRectangle(Keeper &keeper)
{
	std::cout << "\n=== Добавление прямоугольника ===" << std::endl;
	double width, height;
	std::cout << "Введите ширину прямоугольника: ";
	std::cin >> width;
	std::cout << "Введите высоту прямоугольника: ";
	std::cin >> height;
	std::cin.ignore();

	char dimensions[100];
	sprintf(dimensions, "Ширина: %.2lf, Высота: %.2lf", width, height);

	try
	{
		Shape2D *shape = new Shape2D("Прямоугольник", dimensions);
		keeper.add(shape);
		std::cout << "Прямоугольник успешно добавлен!" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Ошибка: " << e.what() << std::endl;
	}
}

void addTriangle(Keeper &keeper)
{
	std::cout << "\n=== Добавление треугольника ===" << std::endl;
	double base, height;
	std::cout << "Введите основание треугольника: ";
	std::cin >> base;
	std::cout << "Введите высоту треугольника: ";
	std::cin >> height;
	std::cin.ignore();

	char dimensions[100];
	sprintf(dimensions, "Основание: %.2lf, Высота: %.2lf", base, height);

	try
	{
		Shape2D *shape = new Shape2D("Треугольник", dimensions);
		keeper.add(shape);
		std::cout << "Треугольник успешно добавлен!" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Ошибка: " << e.what() << std::endl;
	}
}

void addCube(Keeper &keeper)
{
	std::cout << "\n=== Добавление куба ===" << std::endl;
	double side;
	std::cout << "Введите длину стороны куба: ";
	std::cin >> side;
	std::cin.ignore();

	char dimensions[50];
	sprintf(dimensions, "Сторона: %.2lf", side);

	try
	{
		Shape3D *shape = new Shape3D("Куб", dimensions);
		keeper.add(shape);
		std::cout << "Куб успешно добавлен!" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Ошибка: " << e.what() << std::endl;
	}
}

void addSphere(Keeper &keeper)
{
	std::cout << "\n=== Добавление сферы ===" << std::endl;
	double radius;
	std::cout << "Введите радиус сферы: ";
	std::cin >> radius;
	std::cin.ignore();

	char dimensions[50];
	sprintf(dimensions, "Радиус: %.2lf", radius);

	try
	{
		Shape3D *shape = new Shape3D("Сфера", dimensions);
		keeper.add(shape);
		std::cout << "Сфера успешно добавлена!" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Ошибка: " << e.what() << std::endl;
	}
}

void addCylinder(Keeper &keeper)
{
	std::cout << "\n=== Добавление цилиндра ===" << std::endl;
	double radius, height;
	std::cout << "Введите радиус цилиндра: ";
	std::cin >> radius;
	std::cout << "Введите высоту цилиндра: ";
	std::cin >> height;
	std::cin.ignore();

	char dimensions[100];
	sprintf(dimensions, "Радиус: %.2lf, Высота: %.2lf", radius, height);

	try
	{
		Shape3D *shape = new Shape3D("Цилиндр", dimensions);
		keeper.add(shape);
		std::cout << "Цилиндр успешно добавлен!" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Ошибка: " << e.what() << std::endl;
	}
}

void addShape2D(Keeper &keeper)
{
	int choice;
	display2DShapesMenu();
	std::cin >> choice;
	std::cin.ignore();

	switch (choice)
	{
	case 1:
		addCircle(keeper);
		break;
	case 2:
		addRectangle(keeper);
		break;
	case 3:
		addTriangle(keeper);
		break;
	default:
		std::cout << "Неверный выбор!" << std::endl;
	}
}

void addShape3D(Keeper &keeper)
{
	int choice;
	display3DShapesMenu();
	std::cin >> choice;
	std::cin.ignore();

	switch (choice)
	{
	case 1:
		addCube(keeper);
		break;
	case 2:
		addSphere(keeper);
		break;
	case 3:
		addCylinder(keeper);
		break;
	default:
		std::cout << "Неверный выбор!" << std::endl;
	}
}

int main()
{
	Keeper shapes;
	int choice;

	std::cout << "=== Система управления геометрическими фигурами ===" << std::endl;
	std::cout << "Все конструкторы и деструкторы будут отображаться во время работы" << std::endl;

	try
	{
		do
		{
			displayMainMenu();
			std::cin >> choice;
			std::cin.ignore();

			try
			{
				switch (choice)
				{
				case 1:
					addShape2D(shapes);
					break;
				case 2:
					addShape3D(shapes);
					break;
				case 3:
					shapes.displayAll();
					break;
				case 4:
					if (shapes.getSize() > 0)
					{
						shapes.displayAll();
						std::cout << "Выберите фигуру для редактирования (1-" << shapes.getSize() << "): ";
						int index;
						std::cin >> index;
						std::cin.ignore();
						if (index >= 1 && index <= shapes.getSize())
						{
							shapes.editItem(index - 1);
							std::cout << "Фигура успешно отредактирована!" << std::endl;
						}
						else
						{
							std::cout << "Неверный выбор!" << std::endl;
						}
					}
					else
					{
						std::cout << "Нет фигур для редактирования!" << std::endl;
					}
					break;
				case 5:
					if (shapes.getSize() > 0)
					{
						shapes.displayAll();
						std::cout << "Выберите фигуру для удаления (1-" << shapes.getSize() << "): ";
						int index;
						std::cin >> index;
						std::cin.ignore();
						if (index >= 1 && index <= shapes.getSize())
						{
							shapes.remove(index - 1);
							std::cout << "Фигура успешно удалена!" << std::endl;
						}
						else
						{
							std::cout << "Неверный выбор!" << std::endl;
						}
					}
					else
					{
						std::cout << "Нет фигур для удаления!" << std::endl;
					}
					break;
				case 6:
				{
					char filename[100];
					std::cout << "Введите имя файла для сохранения: ";
					std::cin.getline(filename, 100);
					shapes.saveToFile(filename);
					break;
				}
				case 7:
				{
					char filename[100];
					std::cout << "Введите имя файла для загрузки: ";
					std::cin.getline(filename, 100);
					shapes.loadFromFile(filename);
					break;
				}
				case 0:
					std::cout << "До свидания!" << std::endl;
					break;
				default:
					std::cout << "Неверная опция!" << std::endl;
				}
			}
			catch (const std::exception &e)
			{
				std::cout << "Ошибка операции: " << e.what() << std::endl;
			}

		} while (choice != 0);
	}
	catch (const std::exception &e)
	{
		std::cout << "Критическая ошибка: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}