#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "../integration/geometry.h"
//#include "../integration/geometry.cpp"

#include "../query-processing/PointOperations.cpp"

using namespace std;

class PointOperationsTest {
public:
	PointOperationsTest() {

	}
	PointOperationsTest(Point pt1, Point pt2) {

	}
	static void isIntersectingTest(Point pt1, Rectangle rec1,
			bool expectedOutput) {
		//bool expectedOutput;
		bool actualOutput;
		actualOutput = PointOperations::isIntersecting(pt1, rec1);
		//actualOutput = isIntersecting(pt1, pt2);

		cout << actualOutput << endl;
		if (expectedOutput == actualOutput) {
			cout << "Working Fine" << endl;
		} else {
			cout << "Not Working" << endl;
		}

	}
	static void isEqualTest(Point pt1, Point pt2, bool expectedOutput) {
		//bool expectedOutput;
		bool actualOutput;
		actualOutput = PointOperations::isEqual(pt1, pt2);
		//actualOutput = isEqual(pt1, pt2);

		cout << actualOutput << endl;
		if (expectedOutput == actualOutput) {
			cout << "Working Fine" << endl;
		} else {
			cout << "Not Working" << endl;
		}

	}
	static void isDisjointTest(Point pt1, Point pt2, bool expectedOutput) {
		//bool expectedOutput;
		bool actualOutput;
		actualOutput = PointOperations::isDisjoint(pt1, pt2);
		//actualOutput = isDisjoint(pt1, pt2);

		cout << actualOutput << endl;
		if (expectedOutput == actualOutput) {
			cout << "Working Fine" << endl;
		} else {
			cout << "Not Working" << endl;
		}

	}
	static void isWithinTest(Point pt1, Rectangle rec1, bool expectedOutput) {
		//bool expectedOutput;
		bool actualOutput;
		actualOutput = PointOperations::isWithin(pt1, rec1);

		//actualOutput = isWithin(pt1, pt2);
		cout << actualOutput << endl;

		if (expectedOutput == actualOutput) {
			cout << "Working Fine" << endl;
		} else {
			cout << "Not Working" << endl;
		}

	}

	static void isOverlappingTest(Point pt1, Point pt2, bool expectedOutput) {
		//bool expectedOutput;
		bool actualOutput;
		actualOutput = PointOperations::isOverlapping(pt1, pt2);
		//actualOutput = isOverlapping(pt1, pt2);
		cout << actualOutput << endl;

		if (expectedOutput == actualOutput) {
			cout << "Working Fine" << endl;
		} else {
			cout << "Not Working" << endl;
		}

	}
	static void isOverlappingTest(Point pt1, Rectangle rec1,
			bool expectedOutput) {
		//bool expectedOutput;
		bool actualOutput;
		actualOutput = PointOperations::isOverlapping(pt1, rec1);
		//actualOutput = isOverlapping(pt1, pt2);
		cout << actualOutput << endl;

		if (expectedOutput == actualOutput) {
			cout << "Working Fine" << endl;
		} else {
			cout << "Not Working" << endl;
		}

	}
	static void getDistanceTest(Point pt1, Point pt2, float expectedOutput) {
		//float expectedOutput;
		float actualOutput;
		actualOutput = PointOperations::getDistance(pt1, pt2);
		//actualOutput = getDistance(pt1, pt2);
		cout << actualOutput << endl;

		if (expectedOutput == actualOutput) {
			cout << "Working Fine" << endl;
		} else {
			cout << "Not Working" << endl;
		}

	}
	static void getDistanceTest(Point pt1, Rectangle rec1,
			float expectedOutput) {
		//float expectedOutput;
		float actualOutput;
		actualOutput = PointOperations::getDistance(pt1, rec1);
		//actualOutput = getDistance(pt1, pt2);
		cout << actualOutput << endl;

		if (expectedOutput == actualOutput) {
			cout << "Working Fine" << endl;
		} else {
			cout << "Not Working" << endl;
		}

	}

};
int main() {
	Point pt1(3, 3);
	Point pt2(6, 6);
	Point pt3(3, 3);
	Rectangle rec1(1, 1, 4, 4);
	Rectangle rec2(3, 3, 9, 9);
	Rectangle rec3(5, 5, 7, 7);
	PointOperationsTest::isIntersectingTest(pt1, rec1, true);
	PointOperationsTest::isIntersectingTest(pt1, rec2, false);
	PointOperationsTest::isEqualTest(pt1, pt2, false);
	PointOperationsTest::isEqualTest(pt1, pt3, true);
	PointOperationsTest::isDisjointTest(pt1, pt2, true);
	PointOperationsTest::isDisjointTest(pt1, pt3, false);
	PointOperationsTest::isWithinTest(pt1, rec1, true);
	PointOperationsTest::isWithinTest(pt1, rec2, true);
	PointOperationsTest::isWithinTest(pt1, rec3, false);
	PointOperationsTest::isOverlappingTest(pt1, rec1, true);
	PointOperationsTest::isOverlappingTest(pt1, rec2, true);
	PointOperationsTest::isOverlappingTest(pt1, rec3, false);
	PointOperationsTest::isOverlappingTest(pt1, pt3, true);
	PointOperationsTest::isOverlappingTest(pt1, pt2, false);

	Point pt4(0, 5);
	Point pt5(0, 5);
	Point pt6(0, 9);
	Point pt7(5, 5);
	PointOperationsTest::getDistanceTest(pt4, pt6, 4);
	PointOperationsTest::getDistanceTest(pt4, pt5, 0);
	PointOperationsTest::getDistanceTest(pt4, pt7, 5);

	Rectangle rec4(6, 6, 10, 11);
	PointOperationsTest::getDistanceTest(pt7, rec4, 1);

	return 0;
}
