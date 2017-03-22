/*
 * QueryProcessing.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: tejal
 */

#include <iostream>
#include <vector>
#include "query-tree.h"
#include "geometry.h"
#include "OperatorDictionary.cpp"

using namespace std;

class QueryProcessing {

private:
	OperatorDictionary opDict;

	void processQuery (QueryTree qTree) {
		vector<string> root = qTree.root;
		vector<vector<string>> leftFilter = qTree.leftFilter;
		vector<vector<string>> rightFilter = qTree.rightFilter;
		GeometryCollection leftData = qTree.leftData;
		GeometryCollection rightData = qTree.rightData;

	}

	GeometryCollection materializeBranch (vector<vector<string>> filter, GeometryCollection data) {
		// initialize result
		GeometryCollection result, currentRun;
		// get function for next operator to execute
		GeometryCollection (*pointerToGetNext)(vector<vector<string>> filter, int opPosition, GeometryCollection data);
		pointerToGetNext = opDict.getPointerToGetNext(filter[filter.size()-1][0]);
		// get output from first filter and add output to result set
		currentRun = pointerToGetNext(filter);
		while (!currentRun.isEmpty()) {
			result.addAll(currentRun);
			currentRun = pointerToGetNext(filter, filter.size()-2, data);
		}
		return result;
	}

};
