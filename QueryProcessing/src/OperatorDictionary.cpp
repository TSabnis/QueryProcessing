/*
 * OperatorExec.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: tejal
 */

#include <iostream>
#include <vector>
#include "geometry.h"

typedef GeometryCollection (*FunctionPointerType)(vector<vector<string>> filter, int opPosition, GeometryCollection data);

class OperatorDictionary {

public:
	/*
	 * This function will return the pointer to the getNext function
	 * of the operator passed as input to it
	 */
	FunctionPointerType getPointerToGetNext (string operatorName) {
		// switch case logic
	}

};

