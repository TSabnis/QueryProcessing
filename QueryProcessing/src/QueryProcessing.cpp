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
		string* root = qTree.root;
		string* leftFilter = qTree.leftFilter;
		string* rightFilter = qTree.rightFilter;
		GeometryCollection leftData = qTree.leftData;
		GeometryCollection rightData = qTree.rightData;

	}

	vector<Geometry> materializeBranch (vector<vector<string>> filter) {
		// initialize result
		vector<Geometry> result;
		// get function for next operator to execute
		vector<Geometry> (*pointerToGetNext)(vector<vector<string>> filter);
		pointerToGetNext = opDict.getPointerToGetNext(filter[0][0]);
		// get output from first level of filter and add output to result set

	}

};
