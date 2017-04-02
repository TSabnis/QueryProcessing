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

using namespace std;
namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;
namespace mdl = boost::geometry::model;

using namespace std;

class RectangleOperations{
	typedef bg::model::point<double, 2, bg::cs::cartesian> point_t;
	typedef bg::model::box<point_t> box_t;
public:
    static bool isIntersecting (Rectangle rec1, Rectangle rec2){
		point_t pt1(rec1.getCoordinates().at(0),rec1.getCoordinates().at(1));
		point_t pt2(rec1.getCoordinates().at(2),rec1.getCoordinates().at(3));
		point_t pt3(rec2.getCoordinates().at(0),rec2.getCoordinates().at(1));
		point_t pt4(rec2.getCoordinates().at(2),rec2.getCoordinates().at(3));
		box_t box1(pt1,pt2);
		box_t box2(pt3,pt4);
		return bg::intersects(box1, box2);
        //return boost::geometry::intersects(box(mdl::point(rec1.getCoordinates().at(0),rec1.getCoordinates().at(1)), mdl::point(rec1.getCoordinates().at(2),rec1.getCoordinates().at(3))), box(mdl::point(rec2.getCoordinates().at(0),rec2.getCoordinates().at(1)), mdl::point(rec2.getCoordinates().at(2),rec2.getCoordinates().at(3))));
    }

    static bool isEqual (Rectangle rec1, Rectangle rec2){
        return boost::geometry::equals(box_t(point_t(rec1.getCoordinates().at(0),rec1.getCoordinates().at(1)), point_t(rec1.getCoordinates().at(2),rec1.getCoordinates().at(3))), box_t(point_t(rec2.getCoordinates().at(0),rec2.getCoordinates().at(1)), point_t(rec2.getCoordinates().at(2),rec2.getCoordinates().at(3))));
    }

    static bool isDisjoint (Rectangle rec1, Rectangle rec2){
        return boost::geometry::disjoint(box_t(point_t(rec1.getCoordinates().at(0),rec1.getCoordinates().at(1)), point_t(rec1.getCoordinates().at(2),rec1.getCoordinates().at(3))), box_t(point_t(rec2.getCoordinates().at(0),rec2.getCoordinates().at(1)), point_t(rec2.getCoordinates().at(2),rec2.getCoordinates().at(3))));
    }

    static bool isWithin (Rectangle rec1, Rectangle rec2){
        return boost::geometry::within(box_t(point_t(rec1.getCoordinates().at(0),rec1.getCoordinates().at(1)), point_t(rec1.getCoordinates().at(2),rec1.getCoordinates().at(3))), box_t(point_t(rec2.getCoordinates().at(0),rec2.getCoordinates().at(1)), point_t(rec2.getCoordinates().at(2),rec2.getCoordinates().at(3))));
    }

    static bool isOverlapping (Rectangle rec1, Rectangle rec2){
        return boost::geometry::overlaps(box_t(point_t(rec1.getCoordinates().at(0),rec1.getCoordinates().at(1)), point_t(rec1.getCoordinates().at(2),rec1.getCoordinates().at(3))), box_t(point_t(rec2.getCoordinates().at(0),rec2.getCoordinates().at(1)), point_t(rec2.getCoordinates().at(2),rec2.getCoordinates().at(3))));
    }


    static double getDistance (Rectangle rec1, Rectangle rec2){
    	box_t box1(point_t(rec1.getCoordinates().at(0),rec1.getCoordinates().at(1)), point_t(rec1.getCoordinates().at(2),rec1.getCoordinates().at(3)));
		box_t box2(point_t(rec2.getCoordinates().at(0),rec2.getCoordinates().at(1)), point_t(rec2.getCoordinates().at(2),rec2.getCoordinates().at(3)));
        return boost::geometry::distance(box1, box2);
    }

    static double getArea (Rectangle rec1){
    	box_t box1(point_t(rec1.getCoordinates().at(0),rec1.getCoordinates().at(1)), point_t(rec1.getCoordinates().at(2),rec1.getCoordinates().at(3)));
		return boost::geometry::area(box1);
	}


};
