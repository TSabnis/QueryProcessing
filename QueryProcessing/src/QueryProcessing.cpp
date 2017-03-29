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

#define NULL    ((void *)0)

using namespace std;

class QueryProcessing {

private:
	OperatorDictionary opDict;

	QueryResult processQuery (QueryTree qTree) {
		QueryResult queryResult = new QueryResult();
		vector<string> root = qTree.root;
		vector<vector<string>> leftFilter = qTree.leftFilter;
		vector<vector<string>> rightFilter = qTree.rightFilter;
		PointCollection leftDataPoint = qTree.leftDataPoint;
		RectangleCollection leftDataRect = qTree.leftDataRect;
		PointCollection rightDataPoint = qTree.rightDataPoint;
		RectangleCollection rightDataRect = qTree.rightDataRect;

		if (leftDataPoint != NULL && leftDataRect == NULL) {
			PointCollection leftResult = materializeBranch(leftFilter, leftData);
		} else if (leftDataPoint == NULL && leftDataRect != NULL) {
			RectangleCollection leftResult = materializeBranch(leftFilter, leftData);
		}

		if (root[0] == "") {
			if (leftData.getName() == "") {
				//queryResult.setPointCollection((PointCollection)leftResult);
			}
			else {
				//queryResult.setRectangleCollection((RectangleCollection)leftResult);
			}
		}

		return queryResult;
	}

	PointCollection materializeBranch (vector<vector<string>> filter, PointCollection data) {
		// initialize result
		PointCollection result, currentRun;
		// get function for next operator to execute
		PointCollection (*pointerToGetNext)(vector<vector<string>> filter, int opPosition, GeometryCollection data);
		pointerToGetNext = opDict.getPointerToGetNext(filter[filter.size()-1][0]);
		// get output from first filter and add output to result set
		currentRun = pointerToGetNext(filter);
		while (!currentRun.isEmpty()) {
			result.addAll(currentRun);
			currentRun = pointerToGetNext(filter, filter.size()-2, data);
		}
		return result;
	}

	RectangleCollection materializeBranch (vector<vector<string>> filter, RectangleCollection data) {
		// initialize result
		RectangleCollection result, currentRun;
		// get function for next operator to execute
		RectangleCollection (*pointerToGetNext)(vector<vector<string>> filter, int opPosition, GeometryCollection data);
		pointerToGetNext = opDict.getPointerToGetNext(filter[filter.size()-1][0]);
		// get output from first filter and add output to result set
		currentRun = pointerToGetNext(filter);
		while (!currentRun.isEmpty()) {
			result.addAll(currentRun);
			currentRun = pointerToGetNext(filter, filter.size()-2, data);
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

	PointPointCollection distanceJoin (PointCollection leftData, vector<vector<string>> filter, PointCollection rightData) {
		return NULL;
	}

	RectangleRectangleCollection distanceJoin (RectangleCollection leftData, vector<vector<string>> filter, RectangleCollection rightData) {
		return NULL;
	}

	PointRectangleCollection distanceJoin (PointCollection leftData, vector<vector<string>> filter, RectangleCollection rightData) {
		return NULL;
	}

};
