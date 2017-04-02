#include <iostream>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/geometries/box.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/algorithms/intersects.hpp>
#include <boost/foreach.hpp>
#include "../integration/geometry.h"
#include <vector>

using namespace std;
namespace bg = boost::geometry;
namespace bgi = boost::geometry::index;
namespace mdl = boost::geometry::model;

using namespace std;



class PointOperations{
	typedef bg::model::point<double, 2, bg::cs::cartesian> point_t;
	typedef bg::model::box<point_t> box_t;
public:
	static bool isIntersecting (Point p, Rectangle rec){
		box_t box1(point_t(rec.getCoordinates().at(0),rec.getCoordinates().at(1)), point_t(rec.getCoordinates().at(2),rec.getCoordinates().at(3)));
		point_t Pt(p.getCoordinates().at(0), p.getCoordinates().at(1));
		return boost::geometry::intersects(Pt,box1);
	}

	static bool isEqual (Point point1, Point point2){
		return boost::geometry::equals(point_t(point1.getCoordinates().at(0), point1.getCoordinates().at(1)), point_t(point2.getCoordinates().at(0), point2.getCoordinates().at(1)));
	}

	static bool isDisjoint (Point point1, Point point2){
		return boost::geometry::disjoint(point_t(point1.getCoordinates().at(0), point1.getCoordinates().at(1)), point_t(point2.getCoordinates().at(0), point2.getCoordinates().at(1)));
	}

	static bool isWithin (Point point, Rectangle rec){
		return boost::geometry::within(point_t(point.getCoordinates().at(0), point.getCoordinates().at(1)), box_t(point_t(rec.getCoordinates().at(0),rec.getCoordinates().at(1)), point_t(rec.getCoordinates().at(2),rec.getCoordinates().at(3))));
	}

	static bool isOverlapping (Point point1, Point point2){
		return boost::geometry::overlaps(point_t(point1.getCoordinates().at(0), point1.getCoordinates().at(1)), point_t(point2.getCoordinates().at(2), point2.getCoordinates().at(3)));
	}

	static bool isOverlapping (Point point, Rectangle rec){
		return boost::geometry::overlaps(point_t(point.getCoordinates().at(0), point.getCoordinates().at(1)),box_t(point_t(rec.getCoordinates().at(0),rec.getCoordinates().at(1)), point_t(rec.getCoordinates().at(2),rec.getCoordinates().at(3))));
	}

	static double getDistance (Point point1, Point point2){
		typedef bg::model::point<double, 2, bg::cs::cartesian> point_t;
		point_t Pt1(point1.getCoordinates().at(0), point1.getCoordinates().at(1));
		point_t Pt2(point2.getCoordinates().at(0), point2.getCoordinates().at(1));
		return boost::geometry::distance(Pt1, Pt2);
	}
	static double getDistance (Point point, Rectangle rec){
		typedef bg::model::point<double, 2, bg::cs::cartesian> point_t;
		typedef bg::model::box<point_t> box_t;
		point_t Pt1(point.getCoordinates().at(0), point.getCoordinates().at(1));
		box_t box1(point_t(rec.getCoordinates().at(0),rec.getCoordinates().at(1)),point_t(rec.getCoordinates().at(2),(double)rec.getCoordinates().at(3)));
		return boost::geometry::distance(Pt1, box1);
	}

};
