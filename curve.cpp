#include <cmath>

#include "curve.h"


Circle::Circle()
{
	curveType = Type::CIRCLE;
}


Circle::Circle(double rad)
{
	curveType = Type::CIRCLE;
	radius = rad;
	if(radius < 0)
		radius = 0;
}


Point3D Curve::C(double phi)
{
	Point3D point;
	point.X = phi;
	return point;
}


Point3D Circle::C(double phi)
{
	Point3D point;
	point.X = radius * cos(phi);
	point.Y = radius * sin(phi);
	point.Z = 0;

	return point;
}

Point3D Circle::CD(double phi)
{
	Point3D point;
	point.X = radius * (-sin(phi));
	point.Y = radius * cos(phi);
	point.Z = 0;

	return point;
}


Ellipse::Ellipse() : radius2(0)
{
	curveType = Type::ELLIPS;
}


Ellipse::Ellipse(double radX, double radY)
    : radius2(radY)
{
	curveType = Type::ELLIPS;
	radius = radX;
	if(radius < 0)
		radius = 0;
	if(radius2 < 0)
		radius2 = 0;
}


Point3D Ellipse::C(double phi)
{
	Point3D point;
	point.X = radius * cos(phi);
	point.Y = radius2 * sin(phi);
	point.Z = 0;

	return point;
}


Point3D Ellipse::CD(double phi)
{
	Point3D point;
	point.X = radius * (-sin(phi));
	point.Y = radius2 * cos(phi);
	point.Z = 0;

	return point;
}


Helix::Helix() : step(0)
{
	curveType = Type::HELIX;
}


Helix::Helix(double rad, double stp)
    : Circle(rad), step(stp)
{
	curveType = Type::HELIX;
	if(radius < 0)
		radius = 0;
	if(step < 0)
		step = 0;
}


Point3D Helix::C(double phi)
{
	Point3D point = Circle::C(phi);
	point.Z = step * phi / (2 * M_PI);

	return point;
}


Point3D Helix::CD(double phi)
{
	Point3D point = Circle::CD(phi);
	point.Z = step / (2 * M_PI);

	return point;
}


