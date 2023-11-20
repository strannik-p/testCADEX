#ifndef __CURVE_H__
#define __CURVE_H__



struct Point3D{
       double X;
       double Y;
       double Z;
};

class Curve
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


class Circle: public Curve
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

class Ellipse: public Curve
{
public:
	Ellipse();
	Ellipse(double radX, double radY);
	~Ellipse(){};
	// calculate point on curve
	Point3D C(double phi) override;
	// first derivative
	Point3D CD(double phi) override;

private:
        double radius2;
};

class Helix: public Circle
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



#endif /*__CURVE_H__*/
