#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"

class Keeper
{
private:
	Base **items;
	int size;
	int capacity;

	void resize();

public:
	Keeper();
	~Keeper();

	void add(Base *item);
	void remove(int index);
	void displayAll() const;

	int getSize() const { return size; }
	Base *getItem(int index) const;
};

#endif