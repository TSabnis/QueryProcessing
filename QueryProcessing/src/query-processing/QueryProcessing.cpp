/*
 * QueryProcessing.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: tejal
 */

#include <iostream>
#include <vector>
#include "query-tree.h"
#include "query-processing.h"
#include "geometry.h"
#include "OperatorDictionary.cpp"
#include "PointOperations.cpp"
#include "RectangleOperations.cpp"

#define NULL    ((void *)0)
#define TYPE_POINT 1
#define TYPE_RECTANGLE 2
#define TYPE_POINTPOINT 3
#define TYPE_POINTRECTANGLE 4
#define TYPE_RECTANGLERECTANGLE 5
#define POINT "POINT"
#define RECTANGLE "RECTANGLE"
#define POINTPOINT "POINTPOINT"
#define POINTRECTANGLE "POINTRECTANGLE"
#define RECTANGLERECTANGLE "RECTANGLERECTANGLE"
#define DB_NAME ""

using namespace std;

class QueryProcessing {

private:
	OperatorDictionary opDict;

	QueryResult processQuery (QueryTree qTree) {
		QueryResult queryResult;
		vector<string> root = qTree.root;
		vector<vector<string>> leftFilter = qTree.leftFilter;
		vector<vector<string>> rightFilter = qTree.rightFilter;
		PointCollection leftDataPoint = qTree.leftDataPoint;
		RectangleCollection leftDataRect = qTree.leftDataRect;
		PointCollection rightDataPoint = qTree.rightDataPoint;
		RectangleCollection rightDataRect = qTree.rightDataRect;

		// left data is points
		if (leftDataPoint != NULL && leftDataRect == NULL) {
			PointCollection leftResult = materializeBranch(leftFilter, leftDataPoint);
			// no right branch
			if (root[0] == "") {
				queryResult.setPointCollection(leftResult);
			}
			else {
				// right data is points
				if (rightDataPoint != NULL && rightDataRect == NULL) {
					PointCollection rightResult = materializeBranch(rightFilter, rightDataPoint);
					if (root[0] == "knnJoin") {
					}
					else if (root[0] == "rangeJoin") {
					}
					else if (root[0] == "distanceJoin") {
						PointPointCollection distanceJoinResult = distanceJoin(root, leftResult, rightFilter, rightDataPoint);
						queryResult.setPointPointCollection(distanceJoinResult);
					}
				}
				// right data is rectangles
				else if (rightDataPoint == NULL && rightDataRect != NULL) {
					RectangleCollection leftResult = materializeBranch(rightFilter, rightDataRect);
					if (root[0] == "knnJoin") {
					}
					else if (root[0] == "rangeJoin") {
					}
					else if (root[0] == "distanceJoin") {
						PointRectangleCollection distanceJoinResult = distanceJoin(root, leftResult, rightFilter, rightDataRect);
						queryResult.setPointRectangleCollection(distanceJoinResult);
					}
				}
			}
		}
		// left data is rectangles
		else if (leftDataPoint == NULL && leftDataRect != NULL) {
			RectangleCollection leftResult = materializeBranch(leftFilter, leftDataRect);
			// no right branch
			if (root[0] == "") {
				queryResult.setRectangleCollection(leftResult);
			}
			else {
				// right data is points
				if (rightDataPoint != NULL && rightDataRect == NULL) {
					PointCollection rightResult = materializeBranch(rightFilter, rightDataPoint);
					if (root[0] == "knnJoin") {

					}
					else if (root[0] == "rangeJoin") {

					}
					else if (root[0] == "distanceJoin") {
						PointRectangleCollection distanceJoinResult = distanceJoin(root, rightDataPoint, rightFilter, leftResult);
						queryResult.setPointRectangleCollection(distanceJoinResult);
					}
				}
				// right data is rectangles
				else if (rightDataPoint == NULL && rightDataRect != NULL) {
					RectangleCollection leftResult = materializeBranch(rightFilter, rightDataRect);
					if (root[0] == "knnJoin") {
					}
					else if (root[0] == "rangeJoin") {
					}
					else if (root[0] == "distanceJoin") {
					}
				}
			}

		}
		return queryResult;
	}

	PointCollection materializeBranch (vector<vector<string>> filter, PointCollection data) {
		// initialize result
		PointCollection result;
		vector<Point> points = data.getNext(1);
		while (points.size()!=0) {
			bool passedAllOperators = true;
			for (int i=0;i<filter.size();i++) {
				passedAllOperators = passedAllOperators && opDict.applyOperator(filter[i],points[0]);
			}
			if (passedAllOperators) {
				result.insert(points[0]);
			}
			points = data.getNext(1);
		}
		return result;
	}

	RectangleCollection materializeBranch (vector<vector<string>> filter, RectangleCollection data) {
		// initialize result
		RectangleCollection result;
		vector<Rectangle> rects = data.getNext(1);
		while (rects.size()!=0) {
			bool passedAllOperators = true;
			for (int i=0;i<filter.size();i++) {
				passedAllOperators = passedAllOperators && opDict.applyOperator(filter[i],rects[0]);
			}
			if (passedAllOperators) {
				result.insert(rects[0]);
			}
			rects = data.getNext(1);
		}
		return result;
	}

	PointPointCollection rangeJoin (PointCollection leftData, vector<vector<string>> filter, PointCollection rightData) {
		return NULL;
	}

	RectangleRectangleCollection rangeJoin (RectangleCollection leftData, vector<vector<string>> filter, RectangleCollection rightData) {
		return NULL;
	}

	PointRectangleCollection rangeJoin (PointCollection leftData, vector<vector<string>> filter, RectangleCollection rightData) {
		return NULL;
	}

	PointPointCollection knnJoin (vector<string> root, PointCollection leftData, vector<vector<string>> filter, PointCollection rightData) {
		return NULL;
	}

	RectangleRectangleCollection knnJoin (vector<string> root, RectangleCollection leftData, vector<vector<string>> filter, RectangleCollection rightData) {
		return NULL;
	}

	PointRectangleCollection knnJoin (vector<string> root, PointCollection leftData, vector<vector<string>> filter, RectangleCollection rightData) {
		return NULL;
	}

	PointPointCollection distanceJoin (vector<string> root, PointCollection leftData,
			vector<vector<string>> filter, PointCollection rightData) {
		double distThresh = stod(root[1]);
		vector<PointPoint> joinResultVector;
		vector<Point> leftPoints = leftData.getNext(leftData.getSize());
		vector<Point> rightPoints = rightData.getNext(rightData.getSize());
		for (int i=0;i<leftPoints.size();i++) {
			for (int j=0;j<rightPoints.size();j++) {
				if (PointOperations::getDistance(leftPoints[i],rightPoints[j]) <= distThresh) {
					PointPoint pp(leftPoints[i].getCoordinates()[0],leftPoints[i].getCoordinates()[1],
							rightPoints[j].getCoordinates()[0],rightPoints[j].getCoordinates()[1]);
					joinResultVector.insert(joinResultVector.end(),pp);
				}
			}
		}
		PointPointCollection distanceJoinResult(POINTPOINT,DB_NAME,TYPE_POINTPOINT,joinResultVector);
		return distanceJoinResult;
	}

	RectangleRectangleCollection distanceJoin (vector<string> root, RectangleCollection leftData,
			vector<vector<string>> filter, RectangleCollection rightData) {
		double distThresh = stod(root[1]);
		vector<RectangleRectangle> joinResultVector;
		vector<Rectangle> leftRects = leftData.getNext(leftData.getSize());
		vector<Rectangle> rightRects = rightData.getNext(rightData.getSize());
		for (int i=0;i<leftRects.size();i++) {
			for (int j=0;j<rightRects.size();j++) {
				if (RectangleOperations::getDistance(leftRects[i],rightRects[j]) <= distThresh) {
					RectangleRectangle rr(leftRects[i].getCoordinates()[0],leftRects[i].getCoordinates()[1],
							leftRects[i].getCoordinates()[2],leftRects[i].getCoordinates()[3],
							rightRects[j].getCoordinates()[0],rightRects[j].getCoordinates()[1],
							rightRects[j].getCoordinates()[2],rightRects[j].getCoordinates()[3]);
					joinResultVector.insert(joinResultVector.end(),rr);
				}
			}
		}
		PointPointCollection distanceJoinResult(RECTANGLERECTANGLE,DB_NAME,TYPE_RECTANGLERECTANGLE,joinResultVector);
		return distanceJoinResult;
	}

	PointRectangleCollection distanceJoin (vector<string> root, PointCollection leftData,
			vector<vector<string>> filter, RectangleCollection rightData) {
		double distThresh = stod(root[1]);
		vector<PointRectangle> joinResultVector;
		vector<Point> leftPoints = leftData.getNext(leftData.getSize());
		vector<Rectangle> rightRects = rightData.getNext(rightData.getSize());
		for (int i=0;i<leftPoints.size();i++) {
			for (int j=0;j<rightRects.size();j++) {
				if (PointOperations::getDistance(leftPoints[i],rightRects[j]) <= distThresh) {
					PointRectangle pr(leftPoints[i].getCoordinates()[0],leftPoints[i].getCoordinates()[1],
							rightRects[j].getCoordinates()[0],rightRects[j].getCoordinates()[1],
							rightRects[j].getCoordinates()[2],rightRects[j].getCoordinates()[3]);
					joinResultVector.insert(joinResultVector.end(),pr);
				}
			}
		}
		PointPointCollection distanceJoinResult(POINTRECTANGLE,DB_NAME,TYPE_POINTRECTANGLE,joinResultVector);
		return distanceJoinResult;
	}

};
