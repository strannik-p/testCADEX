#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>

#include "../TestCADEX_LIB/curve.h"

struct comp
{
    bool operator()(Curve *l, Curve *r){
        return l->getRadius() < r->getRadius();
    }
};


int main( )
{

    // point 2
    int size = 30;
    std::vector<Curve*> first(size);
    std::vector<Circle> circles;
    std::vector<Ellipse_> ellipses;
    std::vector<Helix> helixes;
    circles.reserve(size);
    ellipses.reserve(size);
    helixes.reserve(size);
    // random seed
    std::srand(time(0));
    for(int i = 0; i < size; i++){
        int x = std::rand()%3 + 1;
        switch(x){
        case 1:
            {
                double rad = std::rand()%1000 / 100.0;
                auto iter {circles.end()};
                circles.push_back(Circle(rad));
                first[i] = &(*iter);
                break;
            }
        case 2:
            {
                double radX = std::rand()%1000 / 100.0;
                double radY = std::rand()%1000 / 100.0;
                auto iter {ellipses.end()};
                ellipses.push_back(Ellipse_(radX, radY));
                first[i] = &(*iter);
                break;
            }
        default:
            {
                double rad = std::rand()%1000 / 100.0;
                double stp = std::rand()%1000 / 100.0;
                auto iter {helixes.end()};
                helixes.push_back(Helix(rad,stp));
                first[i] = &(*iter);
            }
        }
    }

    // point 3
    double phi = 1.0/4*M_PI;
    std::cout << "coordinates point of curves" << std::endl;
    for(auto& n : first){
        Point3D point2 = n->C(phi);
        std::cout << phi/M_PI*180 << " x = " << point2.X << "\t\t y = " << point2.Y \
        << "\t\t z = " << point2.Z  << std::endl;
        //phi += M_PI/6;
    }
    std::cout << std::endl;
    std::cout << "coordinates derivative of curves" << std::endl;
    for(auto& n : first){
        Point3D point2 = n->CD(phi);
        std::cout << phi/M_PI*180 << " x = " << point2.X << "\t y = " << point2.Y \
        << "\t\t z = " << point2.Z  << std::endl;
        //phi += M_PI/6;
    }
    std::cout << std::endl;

    // point 4
    std::vector<Curve*> second;
    second.reserve(first.size());
    for(auto& n : first){
        if(n->getType() == Curve::Type::CIRCLE)
            second.push_back(n);
    }

    // point 5
    std::cout << "sort the second container" << std::endl;
    std::sort(second.begin(), second.end(), comp());
    for(auto& n : second)
        std::cout << n->getRadius() << std::endl;
    std::cout << std::endl;

    // point 6
    double sum = 0;
    for(auto& n : second)
        sum += n->getRadius();
    std::cout << "total sum of radii of all curves in the second container" << std::endl;
    std::cout << sum << std::endl;

    // point 8
    // calculate sum parallel
    sum = 0;
    #pragma omp for
    for(auto& n : second)
        sum += n->getRadius();
    std::cout << "total sum of radii parallel computation" << std::endl;
    std::cout << sum << std::endl;
    std::cout << std::endl;

    system("PAUSE");
    return 0 ;
}


