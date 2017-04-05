/*
 * geometry-collection.cpp
 *
 *  Created on: Apr 3, 2017
 *      Author: vnikhil
 */

#include <string>
#include <vector>
#include "../integration/geometry-collection.h"
using namespace std;

PointCollection::PointCollection() {
	name = "";
	databaseName = "";
	collectionStructure = 0;
}

PointCollection::PointCollection(string tname, string dbName,int collType, vector<Point> v_points) {
	name = tname;
	databaseName = dbName;
	collectionStructure = collType;
	points = v_points;
}

vector<Point> PointCollection::getNext(int n) {
	vector<Point> resultSet;
	int i =0;
	while(i < n){
		resultSet.push_back(this->points.at(i));
		i++;
	}
	return resultSet;
}

int PointCollection::insert(Point point) {
	points.push_back(point);
	return 1;
}

int PointCollection::insertBulk(PointCollection pointCollection) {
	int siz = pointCollection.getSize();
	vector<Point> t_pts = pointCollection.getNext(siz-1);
	for(Point pt : t_pts){
		points.push_back(pt);
	}
	return 1;
}

bool PointCollection::isEmpty() {
	return points.size()==0;
}

int PointCollection::remove(Point point) {
	vector<Point>::iterator it;
	bool found;
	for(it = points.begin(); it!=points.end(); ++it){
		if(it->getCoordinates().at(0) == point.getCoordinates().at(0) &&
				it->getCoordinates().at(1) == point.getCoordinates().at(1)){
			it = points.erase(it);
			--it;
			found = true;
		}
	}
	return found;
}

int PointCollection::getSize() {
	return points.size();
}

string PointCollection::getDBName() {
	return databaseName;
}

string PointCollection::getTableName() {
	return name;
}

/*
 * RECTANGLE COLLECTION
 */

RectangleCollection::RectangleCollection() {
	name = "";
	databaseName = "";
	collectionStructure = 0;
}

RectangleCollection::RectangleCollection(string tname, string dbName,int collType, vector<Rectangle> v_rects) {
	name = tname;
	databaseName = dbName;
	collectionStructure = collType;
	rectangles = v_rects;
}

vector<Rectangle> RectangleCollection::getNext(int n) {
	vector<Rectangle> resultSet;
	int i =0;
	while(i < n){
		resultSet.push_back(this->rectangles.at(i));
		i++;
	}
	return resultSet;
}

int RectangleCollection::insert(Rectangle rect) {
	rectangles.push_back(rect);
	return 1;
}

int RectangleCollection::insertBulk(RectangleCollection RectangleCollection) {
	int siz = RectangleCollection.getSize();
	vector<Rectangle> t_rcts = RectangleCollection.getNext(siz-1);
	for(Rectangle pt : t_rcts){
		rectangles.push_back(pt);
	}
	return 1;
}

bool RectangleCollection::isEmpty() {
	return rectangles.size()==0;
}

int RectangleCollection::remove(Rectangle rct) {
	vector<Rectangle>::iterator it;
	bool found;
	for(it = rectangles.begin(); it!=rectangles.end(); ++it){
		if(it->getCoordinates().at(0) == rct.getCoordinates().at(0) &&
		   it->getCoordinates().at(1) == rct.getCoordinates().at(1) &&
		   it->getCoordinates().at(2) == rct.getCoordinates().at(2) &&
		   it->getCoordinates().at(3) == rct.getCoordinates().at(3))
		{
			it = rectangles.erase(it);
			--it;
			found = true;
		}
	}
	return found;
}

int RectangleCollection::getSize() {
	return rectangles.size();
}

string RectangleCollection::getDBName() {
	return databaseName;
}

string RectangleCollection::getTableName() {
	return name;
}

/*
 *  POINTPOINTCOLLECTION
 *
 */

PointPointCollection::PointPointCollection() {
	name = "";
	databaseName = "";
	collectionStructure = 0;
}

PointPointCollection::PointPointCollection(string tname, string dbName,int collType, vector<PointPoint> v_ppoints) {
	name = tname;
	databaseName = dbName;
	collectionStructure = collType;
	pointPoints = v_ppoints;
}

vector<PointPoint> PointPointCollection::getNext(int n) {
	vector<PointPoint> resultSet;
	int i =0;
	while(i < n){
		resultSet.push_back(this->pointPoints.at(i));
		i++;
	}
	return resultSet;
}

int PointPointCollection::insert(PointPoint point) {
	pointPoints.push_back(point);
	return 1;
}

int PointPointCollection::insertBulk(PointPointCollection ppointCollection) {
	int siz = ppointCollection.getSize();
	vector<PointPoint> t_pts = ppointCollection.getNext(siz-1);
	for(PointPoint pt : t_pts){
		pointPoints.push_back(pt);
	}
	return 1;
}

bool PointPointCollection::isEmpty() {
	return pointPoints.size()==0;
}

//int PointPointCollection::remove(PointPoint point) {
//	vector<PointPoint>::iterator it;
//	bool found;
//	for(it = pointPoints.begin(); it!=pointPoints.end(); ++it){
//		if(it->getCoordinates().at(0) == point.getCoordinates().at(0) &&
//				it->getCoordinates().at(1) == point.getCoordinates().at(1)){
//			it = pointPoints.erase(it);
//			--it;
//			found = true;
//		}
//	}
//	return found;
//}

int PointPointCollection::getSize() {
	return pointPoints.size();
}

string PointPointCollection::getDBName() {
	return databaseName;
}

string PointPointCollection::getTableName() {
	return name;
}


/*
 * 	PointRectangleCollection
 */

PointRectangleCollection::PointRectangleCollection() {
	name = "";
	databaseName = "";
	collectionStructure = 0;
}

PointRectangleCollection::PointRectangleCollection(string tname, string dbName,int collType, vector<PointRectangle> v_prects) {
	name = tname;
	databaseName = dbName;
	collectionStructure = collType;
	pointRectangles = v_prects;
}

vector<PointRectangle> PointRectangleCollection::getNext(int n) {
	vector<PointRectangle> resultSet;
	int i =0;
	while(i < n){
		resultSet.push_back(pointRectangles.at(i));
		i++;
	}
	return resultSet;
}

int PointRectangleCollection::insert(PointRectangle pointR) {
	pointRectangles.push_back(pointR);
	return 1;
}

int PointRectangleCollection::insertBulk(PointRectangleCollection pointRCollection) {
	int siz = pointRCollection.getSize();
	vector<PointRectangle> t_pts = pointRCollection.getNext(siz-1);
	for(PointRectangle pt : t_pts){
		pointRectangles.push_back(pt);
	}
	return 1;
}

bool PointRectangleCollection::isEmpty() {
	return pointRectangles.size()==0;
}

//int PointRectangleCollection::remove(PointRectangle point) {
//	vector<PointRectangle>::iterator it;
//	bool found;
//	for(it = pointPoints.begin(); it!=pointPoints.end(); ++it){
//		if(it->getCoordinates().at(0) == point.getCoordinates().at(0) &&
//				it->getCoordinates().at(1) == point.getCoordinates().at(1)){
//			it = pointPoints.erase(it);
//			--it;
//			found = true;
//		}
//	}
//	Decrement capacity
//	return found;
//}

int PointRectangleCollection::getSize() {
	return pointRectangles.size();
}

string PointRectangleCollection::getDBName() {
	return databaseName;
}

string PointRectangleCollection::getTableName() {
	return name;
}

/*
 * 	RectangleRectangleCollection
 */

RectangleRectangleCollection::RectangleRectangleCollection() {
	name = "";
	databaseName = "";
	collectionStructure = 0;
}

RectangleRectangleCollection::RectangleRectangleCollection(string tname, string dbName,int collType, vector<RectangleRectangle> v_prects) {
	name = tname;
	databaseName = dbName;
	collectionStructure = collType;
	rectangleRectangles = v_prects;
}

vector<RectangleRectangle> RectangleRectangleCollection::getNext(int n) {
	vector<RectangleRectangle> resultSet;
	int i =0;
	while(i < n){
		resultSet.push_back(rectangleRectangles.at(i));
		i++;
	}
	return resultSet;
}

int RectangleRectangleCollection::insert(RectangleRectangle rRect) {
	rectangleRectangles.push_back(rRect);
	return 1;
}

int RectangleRectangleCollection::insertBulk(RectangleRectangleCollection pointRCollection) {
	int siz = pointRCollection.getSize();
	vector<RectangleRectangle> t_pts = pointRCollection.getNext(siz-1);
	for(RectangleRectangle pt : t_pts){
		rectangleRectangles.push_back(pt);
	}
	return 1;
}

bool RectangleRectangleCollection::isEmpty() {
	return rectangleRectangles.size();
}

//int RectangleRectangleCollection::remove(RectangleRectangle point) {
//	vector<RectangleRectangle>::iterator it;
//	bool found;
//	for(it = pointPoints.begin(); it!=pointPoints.end(); ++it){
//		if(it->getCoordinates().at(0) == point.getCoordinates().at(0) &&
//				it->getCoordinates().at(1) == point.getCoordinates().at(1)){
//			it = pointPoints.erase(it);
//			--it;
//			found = true;
//		}
//	}
//	Decrement capacity
//	return found;
//}

int RectangleRectangleCollection::getSize() {
	return rectangleRectangles.size();
}

string RectangleRectangleCollection::getDBName() {
	return databaseName;
}

string RectangleRectangleCollection::getTableName() {
	return name;
}

