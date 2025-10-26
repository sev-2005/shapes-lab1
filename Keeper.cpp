#include "Keeper.h"
#include "Shape2D.h"
#include "Shape3D.h"
#include <iostream>
#include <stdexcept>

class FileException : public std::exception
{
private:
	char *message;

public:
	FileException(const char *msg)
	{
		message = new char[strlen(msg) + 1];
		strcpy(message, msg);
	}
	~FileException() { delete[] message; }
	const char *what() const noexcept override { return message; }
};

class MemoryException : public std::exception
{
private:
	char *message;

public:
	MemoryException(const char *msg)
	{
		message = new char[strlen(msg) + 1];
		strcpy(message, msg);
	}
	~MemoryException() { delete[] message; }
	const char *what() const noexcept override { return message; }
};

Keeper::Keeper() : size(0), capacity(10)
{
	items = new Base *[capacity];
	if (!items)
	{
		throw MemoryException("Ошибка выделения памяти для Keeper");
	}
	for (int i = 0; i < capacity; i++)
	{
		items[i] = nullptr;
	}
	std::cout << "Keeper: Вызван конструктор по умолчанию" << std::endl;
}

Keeper::Keeper(const Keeper &other) : size(other.size), capacity(other.capacity)
{
	items = new Base *[capacity];
	if (!items)
	{
		throw MemoryException("Ошибка выделения памяти для копии Keeper");
	}

	for (int i = 0; i < capacity; i++)
	{
		items[i] = nullptr;
	}

	for (int i = 0; i < size; i++)
	{
		Shape2D *shape2d = dynamic_cast<Shape2D *>(other.items[i]);
		Shape3D *shape3d = dynamic_cast<Shape3D *>(other.items[i]);

		if (shape2d)
		{
			items[i] = new Shape2D(*shape2d);
		}
		else if (shape3d)
		{
			items[i] = new Shape3D(*shape3d);
		}
	}
	std::cout << "Keeper: Вызван конструктор копирования" << std::endl;
}

Keeper::~Keeper()
{
	for (int i = 0; i < size; i++)
	{
		delete items[i];
	}
	delete[] items;
	std::cout << "Keeper: Вызван деструктор" << std::endl;
}

Keeper &Keeper::operator=(const Keeper &other)
{
	if (this != &other)
	{
		for (int i = 0; i < size; i++)
		{
			delete items[i];
		}
		delete[] items;

		size = other.size;
		capacity = other.capacity;
		items = new Base *[capacity];

		for (int i = 0; i < capacity; i++)
		{
			items[i] = nullptr;
		}

		for (int i = 0; i < size; i++)
		{
			Shape2D *shape2d = dynamic_cast<Shape2D *>(other.items[i]);
			Shape3D *shape3d = dynamic_cast<Shape3D *>(other.items[i]);

			if (shape2d)
			{
				items[i] = new Shape2D(*shape2d);
			}
			else if (shape3d)
			{
				items[i] = new Shape3D(*shape3d);
			}
		}
	}
	std::cout << "Keeper: Вызван оператор присваивания" << std::endl;
	return *this;
}

void Keeper::resize()
{
	if (size >= capacity)
	{
		int newCapacity = capacity * 2;
		Base **newItems = new Base *[newCapacity];
		if (!newItems)
		{
			throw MemoryException("Ошибка изменения размера массива Keeper");
		}

		for (int i = 0; i < size; i++)
		{
			newItems[i] = items[i];
		}
		for (int i = size; i < newCapacity; i++)
		{
			newItems[i] = nullptr;
		}

		delete[] items;
		items = newItems;
		capacity = newCapacity;
	}
}

void Keeper::add(Base *item)
{
	if (!item)
	{
		throw std::invalid_argument("Нельзя добавить пустой объект");
	}
	resize();
	items[size++] = item;
	std::cout << "Keeper: Добавлен объект " << item->getType() << std::endl;
}

void Keeper::remove(int index)
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Неверный индекс для удаления");
	}

	std::cout << "Keeper: Удаляется объект " << items[index]->getType() << std::endl;
	delete items[index];

	for (int i = index; i < size - 1; i++)
	{
		items[i] = items[i + 1];
	}
	items[--size] = nullptr;
}

void Keeper::displayAll() const
{
	if (size == 0)
	{
		std::cout << "В коллекции нет фигур." << std::endl;
		return;
	}

	std::cout << "\n=== Все фигуры (" << size << ") ===" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << "\n"
				  << i + 1 << ". ";
		items[i]->display();
	}
}

void Keeper::saveToFile(const char *filename) const
{
	std::ofstream file(filename);
	if (!file.is_open())
	{
		throw FileException("Не удалось открыть файл для записи");
	}

	file << size << "\n";
	for (int i = 0; i < size; i++)
	{
		items[i]->saveToFile(file);
	}
	file.close();
	std::cout << "Данные успешно сохранены в " << filename << "!" << std::endl;
}

void Keeper::loadFromFile(const char *filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		throw FileException("Не удалось открыть файл для чтения");
	}

	for (int i = 0; i < size; i++)
	{
		delete items[i];
	}
	size = 0;

	int fileSize;
	file >> fileSize;
	file.ignore();

	for (int i = 0; i < fileSize; i++)
	{
		char typeBuffer[10];
		file.getline(typeBuffer, 10);

		if (strcmp(typeBuffer, "2D") == 0)
		{
			Shape2D *shape = new Shape2D();
			shape->loadFromFile(file);
			add(shape);
		}
		else if (strcmp(typeBuffer, "3D") == 0)
		{
			Shape3D *shape = new Shape3D();
			shape->loadFromFile(file);
			add(shape);
		}
	}
	file.close();
	std::cout << "Данные успешно загружены из " << filename << "!" << std::endl;
}

void Keeper::editItem(int index)
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Неверный индекс для редактирования");
	}
	items[index]->edit();
}

Base *Keeper::getItem(int index) const
{
	if (index < 0 || index >= size)
		return nullptr;
	return items[index];
}