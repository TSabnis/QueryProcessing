#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "geometry.h"
#include "RectangleOperations.cpp"
using namespace std;

class RectangleOperationsTest {
	RectangleOperationsTest() {

	}
	RectangleOperationsTest(Rectangle rec1, Rectangle rec2) {

	}
	void isIntersectingTest(Rectangle rec1, Rectangle rec2) {
		bool expectedOutput;
		bool actualOutput;
		actualOutput = RectangleOperations::isIntersecting(rec1, rec2);
		cout << actualOutput;
		if (expectedOutput == actualOutput) {
			cout << "Working Fine";
		} else {
			cout << "Not Working";
		}

	}
	void isEqualTest(Rectangle rec1, Rectangle rec2) {
		bool expectedOutput;
		bool actualOutput;
		actualOutput = RectangleOperations::isEqual(rec1, rec2);
		cout << actualOutput;
		if (expectedOutput == actualOutput) {
			cout << "Working Fine";
		} else {
			cout << "Not Working";
		}

	}
	void isDisjointTest(Rectangle rec1, Rectangle rec2) {
		bool expectedOutput;
		bool actualOutput;
		actualOutput = RectangleOperations::isDisjoint(rec1, rec2);
		cout << actualOutput;
		if (expectedOutput == actualOutput) {
			cout << "Working Fine";
		} else {
			cout << "Not Working";
		}

	}
	void isWithinTest(Rectangle rec1, Rectangle rec2) {
		bool expectedOutput;
		bool actualOutput;
		actualOutput = RectangleOperations::isWithin(rec1, rec2);
		cout << actualOutput;
		if (expectedOutput == actualOutput) {
			cout << "Working Fine";
		} else {
			cout << "Not Working";
		}

	}

	void isOverlappingTest(Rectangle rec1, Rectangle rec2) {
		bool expectedOutput;
		bool actualOutput;
		actualOutput = RectangleOperations::isOverlapping(rec1, rec2);
		if (expectedOutput == actualOutput) {
			cout << "Working Fine";
		} else {
			cout << "Not Working";
		}

	}
	void getDistanceTest(Rectangle rec1, Rectangle rec2) {
		float expectedOutput;
		float actualOutput;
		actualOutput = RectangleOperations::getDistance(rec1, rec2);
		if (expectedOutput == actualOutput) {
			cout << "Working Fine";
		} else {
			cout << "Not Working";
		}

	}

};
int main() {
	Rectangle rec1 = Rectangle(2.3, 5.6, 7.8, 9.2);
	Rectangle rec2 = Rectangle(6.7, 4.3, 8.3, 10.2);
	RectangleOperationsTest rectangleOperationsTest(rec1, rec2);
	rectangleOperationsTest.isIntersectingTest(rec1, rec2);
	rectangleOperationsTest.isEqualTest(rec1, rec2);
	rectangleOperationsTest.isDisjointTest(rec1, rec2);
	rectangleOperationsTest.isWithinTest(rec1, rec2);
	rectangleOperationsTest.isOverlappingTest(rec1, rec2);
	rectangleOperationsTest.getDistanceTest(rec1, rec2);
	return 0;
}
