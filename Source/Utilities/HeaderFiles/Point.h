#pragma once
class Point
{
public:
	Point() {};
	Point(int x, int y);

	int GetcoordinateX();
	void SetCoordinateX(int x);
	int GetcoordinateY();
	void SetCoordinateY(int y);
private:
	int coordinateX;
	int coordinateY;
};

