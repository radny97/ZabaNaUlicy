#include "Utilities/HeaderFiles/Point.h"

Point::Point(int x, int y)
{
	this->coordinateX = x;
	this->coordinateY = y;
}

int Point::GetcoordinateX()
{
	return this->coordinateX;
}

void Point::SetCoordinateX(int x)
{
	this->coordinateX = x;
}

int Point::GetcoordinateY()
{
	return this->coordinateY;
}

void Point::SetCoordinateY(int y)
{
	this->coordinateY = y;
}