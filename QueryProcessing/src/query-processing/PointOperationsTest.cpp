#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "geometry.h"
#include "PointOperations.cpp"
using namespace std;

class PointOperationsTest {
	Point point;
	Point point1;
	Point point2;
	Rectangle rectangle;


	PointOperationsTest() {

	}
	PointOperationsTest(Point pt, Point pt1, Point pt2, Rectangle rec) {
		point  = pt;
		point1 = pt1;
		point2 = pt2;
		rectangle = rec;

	}
	void isIntersectingTest(bool expectedValueSentFromMain) {
		bool expectedOutput = expectedValueSentFromMain;
		bool actualOutput;
		actualOutput = PointOperations::isIntersecting(point, rectangle);
		cout << actualOutput;
		if (expectedOutput == actualOutput) {
			cout << "Working Fine";
		} else {
			cout << "Not Working";
		}

	}
	void isEqualTest(bool expectedValueSentFromMain) {
		bool expectedOutput= expectedValueSentFromMain;
		bool actualOutput;
		actualOutput = PointOperations::isEqual(point1, point2);
		cout << actualOutput;
		if (expectedOutput == actualOutput) {
			cout << "Working Fine";
		} else {
			cout << "Not Working";
		}

	}
	void isDisjointTest(bool expectedValueSentFromMain) {
		bool expectedOutput= expectedValueSentFromMain;
		bool actualOutput;
		actualOutput = PointOperations::isDisjoint(point1, point2);
		cout << actualOutput;
		if (expectedOutput == actualOutput) {
			cout << "Working Fine";
		} else {
			cout << "Not Working";
		}
	}
	void isWithinTest(bool expectedValueSentFromMain) {
		bool expectedOutput= expectedValueSentFromMain;
		bool actualOutput;
		actualOutput = PointOperations::isWithin(point, rectangle);
		cout << actualOutput;
		if (expectedOutput == actualOutput) {
			cout << "Working Fine";
		} else {
			cout << "Not Working";
		}

	}
	void isOverlappingTest(bool expectedValueSentFromMain) {
		bool expectedOutput= expectedValueSentFromMain;
		bool actualOutput;
		actualOutput = PointOperations::isOverlapping(point1, point2);
		cout << actualOutput;
		if (expectedOutput == actualOutput) {
			cout << "Working Fine";
		} else {
			cout << "Not Working";
		}

	}
	void isOverlappingPtRectTest(bool expectedValueSentFromMain) {
		bool expectedOutput= expectedValueSentFromMain;
		bool actualOutput;
		actualOutput = PointOperations::isOverlapping(point1, rectangle);
		cout << actualOutput;
		if (expectedOutput == actualOutput) {
			cout << "Working Fine";
		} else {
			cout << "Not Working";
		}

	}
	void getDistanceTest(float expectedValueSentFromMain) {
		float expectedOutput = expectedValueSentFromMain;
		float actualOutput;
		actualOutput = PointOperations::getDistance(point1, point2);
		cout << actualOutput;
		if (expectedOutput == actualOutput) {
			cout << "Working Fine";
		} else {
			cout << "Not Working";
		}

	}
	void getDistancePtRectTest(float expectedValueSentFromMain) {
		float expectedOutput= expectedValueSentFromMain;
		float actualOutput;
		actualOutput = PointOperations::getDistance(point, rectangle);
		cout << actualOutput;
		if (expectedOutput == actualOutput) {
			cout << "Working Fine";
		} else {
			cout << "Not Working";
		}

	}

};
int main() {
	Point pt = new Point(2.3, 3.4);
	Point pt1 = new Point(4.5, 5.6);
	Point pt2= new Point(5.6, 6.7);
	Rectangle rec = new Rectangle(2.3, 3.4, 4.5, 5.6);
	PointOperationsTest pointOperationsTest(pt, pt1, pt2, rec);
	pointOperationsTest.isIntersectingTest(true);
	pointOperationsTest.isEqualTest(true);
	pointOperationsTest.isDisjointTest(true);
	pointOperationsTest.isWithinTest(true);
	pointOperationsTest.isOverlappingTest(true);
	pointOperationsTest.isOverlappingPtRectTest(true);
	pointOperationsTest.getDistanceTest(20.00);
	pointOperationsTest.getDistancePtRectTest(20.00);
	return 0;
}
