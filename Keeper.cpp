#include "Keeper.h"
#include <iostream>

Keeper::Keeper() : size(0), capacity(10)
{
	items = new Base *[capacity];
	for (int i = 0; i < capacity; i++)
	{
		items[i] = nullptr;
	}
	std::cout << "Keeper: Default constructor called" << std::endl;
}

Keeper::~Keeper()
{
	for (int i = 0; i < size; i++)
	{
		delete items[i];
	}
	delete[] items;
	std::cout << "Keeper: Destructor called" << std::endl;
}

void Keeper::add(Base *item)
{
	if (!item)
		return;
	// resize() will be implemented in next commit
	items[size++] = item;
	std::cout << "Keeper: Added item " << item->getType() << std::endl;
}

void Keeper::displayAll() const
{
	if (size == 0)
	{
		std::cout << "No items in keeper." << std::endl;
		return;
	}

	std::cout << "\n=== All Items ===" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << i + 1 << ". ";
		items[i]->display();
	}
}

// Other methods will be implemented in next commits