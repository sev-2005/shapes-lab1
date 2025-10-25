#ifndef SHAPE3D_H
#define SHAPE3D_H

#include "Base.h"
#include <cstring>

class Shape3D : public Base
{
protected:
	char *type;
	char *dimensions;
	double volume;
	char *drawing2D;

	void calculateVolume();

public:
	Shape3D();
	Shape3D(const char *shapeType, const char *dims, const char *draw2D = nullptr);
	Shape3D(const Shape3D &other);
	~Shape3D();

	Shape3D &operator=(const Shape3D &other);

	const char *getType() const override { return type; }
	const char *getDimensions() const { return dimensions; }
	double getVolume() const { return volume; }
	const char *getDrawing2D() const { return drawing2D; }

	void setType(const char *shapeType);
	void setDimensions(const char *dims);
	void setDrawing2D(const char *draw2D);

	void display() const override;
	void edit() override;
	void saveToFile(std::ostream &os) const override;
	void loadFromFile(std::istream &is) override;
};

#endif