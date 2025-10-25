#include <iostream>
#include "Keeper.h"
#include "Shape2D.h"
#include "Shape3D.h"

int main()
{
	std::cout << "=== Shapes Management System - Basic Test ===" << std::endl;

	Keeper shapes;

	// Test basic functionality
	shapes.add(new Shape2D("Circle", "Radius: 5"));
	shapes.add(new Shape2D("Rectangle", "Width: 10, Height: 5"));
	shapes.add(new Shape3D("Cube", "Side: 3"));
	shapes.add(new Shape3D("Sphere", "Radius: 4"));

	std::cout << "\n=== Displaying All Shapes ===" << std::endl;
	shapes.displayAll();

	std::cout << "Total shapes: " << shapes.getSize() << std::endl;

	return 0;
}