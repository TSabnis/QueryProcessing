#include <iostream>
#include <vector>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/geometries/box.hpp>
#include <boost/foreach.hpp>
#include "../integration/query-processing.h"


using namespace std;
namespace bg = boost::geometry;
typedef bg::model::point<float, 2, bg::cs::cartesian> point;
typedef bg::model::box<point> box;

static bool isIntersecting (Point p, Rectangle rec){

	return boost::geometry::intersects(point(p.getCoordinates().at(0), p.getCoordinates().at(1)), box(point(rec.getCoordinates().at(0),rec.getCoordinates().at(1)), point(rec.getCoordinates().at(2),rec.getCoordinates().at(3))));
}

static bool isEqual (Point point1, Point point2){
	return boost::geometry::equals(point(point1.getCoordinates().at(0), point1.getCoordinates().at(1)), point(point2.getCoordinates().at(0), point2.getCoordinates().at(1)));
}

static bool isDisjoint (Point point1, Point point2){
	return boost::geometry::disjoint(point(point1.getCoordinates().at(0), point1.getCoordinates().at(1)), point(point2.getCoordinates().at(0), point2.getCoordinates().at(1)));
}

static bool isWithin (Point point1, Rectangle rec){
	return boost::geometry::within(point(point1.getCoordinates().at(0), point1.getCoordinates().at(1)), box(point(rec.getCoordinates().at(0),rec.getCoordinates().at(1)), point(rec.getCoordinates().at(2),rec.getCoordinates().at(3))));
}
static double getDistance (Point point1, Point point2){
    return boost::geometry::distance(point(point1.getCoordinates().at(0), point1.getCoordinates().at(1)), point(point2.getCoordinates().at(0), point2.getCoordinates().at(1)));
}

/*static bool isOverlapping (Point point1, Point point2){
	return boost::geometry::overlaps(point(point1.getCoordinates().at(0), point1.getCoordinates().at(1)), point(point2.getCoordinates().at(2), point2.getCoordinates().at(3)));
}

static bool isOverlapping (Point point1, Rectangle rec){
	//return boost::geometry::overlaps(point(point1.getCoordinates().at(0), point1.getCoordinates().at(1)), box(point(rec.getCoordinates().at(0),rec.getCoordinates().at(1)), point(rec.getCoordinates().at(2),rec.getCoordinates().at(3))));
	//return boost::geometry::overlaps(point(point1.getCoordinates().at(0), point1.getCoordinates().at(1)), point(rec.getCoordinates().at(0), rec.getCoordinates().at(1)));
	return boost::geometry::within(point(point1.getCoordinates().at(0), point1.getCoordinates().at(1)), box(point(rec.getCoordinates().at(0),rec.getCoordinates().at(1)), point(rec.getCoordinates().at(2),rec.getCoordinates().at(3))));

}*/


static double getDistance (Point point1, Rectangle rec){
	return boost::geometry::distance(point(point1.getCoordinates().at(0), point1.getCoordinates().at(1)), box(point(rec.getCoordinates().at(0),rec.getCoordinates().at(1)), point(rec.getCoordinates().at(2),rec.getCoordinates().at(3))));
}


