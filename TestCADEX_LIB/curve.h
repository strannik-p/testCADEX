#ifndef __CURVE_H__
#define __CURVE_H__

#include <windows.h>

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif


struct Point3D{
       double X;
       double Y;
       double Z;
};

class DLL_EXPORT Curve
{
public:
	enum class Type : short {CURVE, CIRCLE, ELLIPS, HELIX};
	Curve() : curveType(Type::CURVE), radius(0){};
	~Curve(){};
	// calculate point on curve
	virtual Point3D C(double phi) = 0;
	// first derivative
	virtual Point3D CD(double phi) = 0;
	Type getType() {return curveType;};
	double getRadius() {return radius;};

protected:
	Type curveType;
	double radius;
};


class DLL_EXPORT Circle: public Curve
{
public:
	Circle();
	Circle(double rad);
	~Circle(){};
	// calculate point on curve
	Point3D C(double phi) override;
	// first derivative
	Point3D CD(double phi) override;
};

class DLL_EXPORT Ellipse_: public Curve
{
public:
	Ellipse_();
	Ellipse_(double radX, double radY);
	~Ellipse_(){};
	// calculate point on curve
	Point3D C(double phi) override;
	// first derivative
	Point3D CD(double phi) override;

private:
        double radius2;
};

class DLL_EXPORT Helix: public Circle
{
public:
	Helix();
	Helix(double rad, double stp);
	~Helix(){};
	// calculate point on curve
	Point3D C(double phi) override;
	// first derivative
	Point3D CD(double phi) override;
	//Type getType() override {return curveType;};

private:
    double step;
};

#ifdef __cplusplus
}
#endif


#endif /*__CURVE_H__*/
