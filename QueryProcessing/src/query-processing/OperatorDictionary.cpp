/*
 * OperatorExec.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: tejal
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "../integration/geometry.h"
#include "PointOperations.cpp"
#include "RectangleOperations.cpp"
using namespace std;

class OperatorDictionary {

public:

	PointOperations po;
	RectangleOperations ro;

	bool applyFilterBy (vector<string> filterDetails, Point inputPoint) {
		bool isCriterionSatisfied = false;
		double compareVal = stod(filterDetails[3]);
		string operatorName = filterDetails[2];

		if (filterDetails[1] == "distance") {
			double metricVal;
			if (filterDetails.size()==8) {
				metricVal = po.getDistance(inputPoint,
					Rectangle(stod(filterDetails[4]),stod(filterDetails[5]),stod(filterDetails[6]),stod(filterDetails[7])));
			}
			else {
				metricVal = po.getDistance(inputPoint,
					Point(stod(filterDetails[4]),stod(filterDetails[5])));
			}
			if(operatorName == "gt" && metricVal > compareVal)
				isCriterionSatisfied = true;
			else if(operatorName == "ge" && metricVal >= compareVal)
				isCriterionSatisfied = true;
			else if(operatorName == "lt" && metricVal < compareVal)
				isCriterionSatisfied = true;
			else if(operatorName == "le"&& metricVal <= compareVal)
				isCriterionSatisfied = true;
			else if(operatorName == "eq" && metricVal == compareVal)
				isCriterionSatisfied = true;
		}
		return isCriterionSatisfied;
	}

	bool applyFilterBy (vector<string> filterDetails, Rectangle inputRect) {
		bool isCriterionSatisfied = false;
		double compareVal = stod(filterDetails[3]);
		string operatorName = filterDetails[2];

		if (filterDetails[1] == "distance") {
			double metricVal;
			if (filterDetails.size()==8) {
				metricVal = ro.getDistance(inputRect,
					Rectangle(stod(filterDetails[4]),stod(filterDetails[5]),stod(filterDetails[6]),stod(filterDetails[7])));
			}
			else {
				metricVal = po.getDistance(Point(stod(filterDetails[4]),stod(filterDetails[5])), inputRect);
			}
			if(operatorName == "gt" && metricVal > compareVal)
				isCriterionSatisfied = true;
			else if(operatorName == "ge" && metricVal >= compareVal)
				isCriterionSatisfied = true;
			else if(operatorName == "lt" && metricVal < compareVal)
				isCriterionSatisfied = true;
			else if(operatorName == "le"&& metricVal <= compareVal)
				isCriterionSatisfied = true;
			else if(operatorName == "eq" && metricVal == compareVal)
				isCriterionSatisfied = true;
		}
		else if (filterDetails[1] == "area") {
			double metricVal = ro.getArea(inputRect);
			if(operatorName == "gt" && metricVal > compareVal)
				isCriterionSatisfied = true;
			else if(operatorName == "ge" && metricVal >= compareVal)
				isCriterionSatisfied = true;
			else if(operatorName == "lt" && metricVal < compareVal)
				isCriterionSatisfied = true;
			else if(operatorName == "le"&& metricVal <= compareVal)
				isCriterionSatisfied = true;
			else if(operatorName == "eq" && metricVal == compareVal)
				isCriterionSatisfied = true;
		}
		return isCriterionSatisfied;
	}

	bool applyOperator (vector<string> filterDetails, Point inputPoint) {
		if (filterDetails[0] == "filterBy") {
			return applyFilterBy(filterDetails, inputPoint);
		}
		else {
			return false;
		}
	}

	bool applyOperator (vector<string> filterDetails, Rectangle inputRect) {
		if (filterDetails[0] == "filterBy") {
			return applyFilterBy(filterDetails, inputRect);
		}
		else {
			return false;
		}
	}
};
