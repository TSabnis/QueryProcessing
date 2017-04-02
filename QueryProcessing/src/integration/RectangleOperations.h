//
// Created by raha on 4/1/17.
//

#ifndef QUERYPROCESSING_RECTANGLEOPERATIONS_H
#define QUERYPROCESSING_RECTANGLEOPERATIONS_H
//
// Created by raha on 3/26/17.
//

#include <iostream>
//#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/geometries/box.hpp>
#include <boost/foreach.hpp>
#include "../integration/geometry.h"
#include <vector>
#include <boost/geometry/algorithms/intersects.hpp>
#include <boost/geometry/algorithms/equals.hpp>
#include <boost/geometry/algorithms/overlaps.hpp>
#include <boost/geometry/algorithms/distance.hpp>

using namespace std;
namespace bg = boost::geometry;
typedef bg::model::point<float, 2, bg::cs::cartesian> point;
typedef bg::model::box<point> box;

using namespace std;

class RectangleOperations{
public:
    static bool isIntersecting (Rectangle rec1, Rectangle rec2);

    static bool isEqual (Rectangle rec1, Rectangle rec2);
    static bool isDisjoint (Rectangle rec1, Rectangle rec2);
    static bool isWithin (Rectangle rec1, Rectangle rec2);
    static bool isOverlapping (Rectangle rec1, Rectangle rec2);
    static double getDistance (Rectangle rec1, Rectangle rec2);


};
#endif //QUERYPROCESSING_RECTANGLEOPERATIONS_H
