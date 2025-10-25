#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base
{
public:
	virtual ~Base() = default;

	virtual void display() const = 0;
	virtual void edit() = 0;
	virtual void saveToFile(std::ostream &os) const = 0;
	virtual void loadFromFile(std::istream &is) = 0;
	virtual const char *getType() const = 0;
};

#endif