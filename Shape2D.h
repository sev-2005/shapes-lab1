#ifndef SHAPE2D_H
#define SHAPE2D_H

#include "Base.h"
#include <cstring>
#include <cmath>

class Shape2D : public Base
{
private:
	char *type;
	char *dimensions;
	double area;
	char *drawing;

	void calculateArea();
	void generateDrawing();

public:
	Shape2D();
	Shape2D(const char *shapeType, const char *dims);
	Shape2D(const Shape2D &other);
	~Shape2D();

	Shape2D &operator=(const Shape2D &other);

	const char *getType() const override { return type; }
	const char *getDimensions() const { return dimensions; }
	double getArea() const { return area; }
	const char *getDrawing() const { return drawing; }

	void setType(const char *shapeType);
	void setDimensions(const char *dims);

	void display() const override;
	void edit() override;
	void saveToFile(std::ostream &os) const override;
	void loadFromFile(std::istream &is) override;
};

#endif