#ifndef SHAPE3D_H
#define SHAPE3D_H

#include "Base.h"
#include <cstring>
#include <cmath>

class Shape3D : public Base
{
private:
	char *type;
	char *dimensions;
	double volume;
	char *drawing2D;

	void calculateVolume();
	void generateDrawing2D();

public:
	Shape3D();
	Shape3D(const char *shapeType, const char *dims);
	Shape3D(const Shape3D &other);
	~Shape3D();

	Shape3D &operator=(const Shape3D &other);

	const char *getType() const override { return type; }
	const char *getDimensions() const { return dimensions; }
	double getVolume() const { return volume; }
	const char *getDrawing2D() const { return drawing2D; }

	void setType(const char *shapeType);
	void setDimensions(const char *dims);

	void display() const override;
	void edit() override;
	void saveToFile(std::ostream &os) const override;
	void loadFromFile(std::istream &is) override;
};

#endif