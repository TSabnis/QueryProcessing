/*
 * QueryTree.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: tejal
 */

#include <iostream>
#include <vector>
#include "GeometryCollection.h"

using namespace std;

class QueryTree {

	public:
		vector<string> root;
		vector<vector<string>> leftFilter;
		GeometryCollection leftData;
		vector<vector<string>> rightFilter;
		GeometryCollection rightData;


};

