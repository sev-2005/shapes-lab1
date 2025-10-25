#ifndef SHAPE2D_H
#define SHAPE2D_H

#include "Base.h"
#include <cstring>

class Shape2D : public Base
{
protected:
	char *type;
	char *dimensions;
	double area;
	char *drawing;

	void calculateArea();

public:
	Shape2D();
	Shape2D(const char *shapeType, const char *dims, const char *draw = nullptr);
	Shape2D(const Shape2D &other);
	~Shape2D();

	Shape2D &operator=(const Shape2D &other);

	const char *getType() const override { return type; }
	const char *getDimensions() const { return dimensions; }
	double getArea() const { return area; }
	const char *getDrawing() const { return drawing; }

	void setType(const char *shapeType);
	void setDimensions(const char *dims);
	void setDrawing(const char *draw);

	void display() const override;
	void edit() override;
	void saveToFile(std::ostream &os) const override;
	void loadFromFile(std::istream &is) override;
};

#endif