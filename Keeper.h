#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"
#include <fstream>

class Keeper
{
private:
	Base **items;
	int size;
	int capacity;

	void resize();

public:
	Keeper();
	Keeper(const Keeper &other);
	~Keeper();

	Keeper &operator=(const Keeper &other);

	void add(Base *item);
	void remove(int index);
	void displayAll() const;
	void saveToFile(const char *filename) const;
	void loadFromFile(const char *filename);
	void editItem(int index);

	int getSize() const { return size; }
	Base *getItem(int index) const;
};

#endif