/*
 * Range.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: tejal
 */

#include <iostream>
#include <vector>
#include "geometry.h"
#include "OperatorDictionary.cpp"

using namespace std;

class Range {

private:
	OperatorDictionary opDict;

	GeometryCollection getNext(vector<vector<string>> filter, int opPosition, GeometryCollection data) {
		GeometryCollection result, input;
		vector<Geometry> (*pointerToGetNext)(vector<vector<string>> filter);
		pointerToGetNext = opDict.getPointerToGetNext(filter[opPosition][0]);
		if (opPosition==0) {
			input = data.getNext(1);
		}
		else {
			input = pointerToGetNext(filter, opPosition-1, data);
		}
		while (!input.isEmpty()) {
			for (int i=0;i<input.size();i++) {
				Geometry geo = input.get(i);
				if (true) {
					result.insert(geo);
				}
			}
			if (opPosition==0) {
				input = data.getNext(1);
			}
			else {
				input = pointerToGetNext(filter, opPosition-1, data);
			}
		}
		return result;
	}

};


