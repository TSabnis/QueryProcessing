//
// Created by raha on 4/1/17.
//

#ifndef POINTOPERATIONS_H_
#define POINTOPERATIONS_H_

#include <iostream>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/geometries/box.hpp>
#include <boost/foreach.hpp>
#include "../integration/geometry.h"
#include <vector>

using namespace std;
namespace bg = boost::geometry;

using namespace std;
typedef bg::model::point<float, 2, bg::cs::cartesian> point;
typedef bg::model::box<point> box;

class PointOperations{
public:
    static bool isIntersecting (Point p, Rectangle rec);
    static bool isEqual (Point point1, Point point2);
    static bool isDisjoint (Point point1, Point point2);
    static bool isWithin (Point point1, Rectangle rec);
    static bool isOverlapping (Point point1, Point point2);
    static double getDistance (Point point1, Point point2);
    static double getDistance (Point point1, Rectangle rec);

};

#endif //QUERYPROCESSING_POINTOPERATIONS_H
