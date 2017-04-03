#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "../integration/geometry.cpp"
#include "../query-processing/PointOperations.cpp"

using namespace std;

//class PointOperationsTest {
//	Point point;
//	Point point1;
//	Point point2;
//	Rectangle rectangle;
//

////	PointOperationsTest() {
////
////	}
////	PointOperationsTest(Point pt, Point pt1, Point pt2, Rectangle rec) {
////		point  = pt;
////		point1 = pt1;
////		point2 = pt2;
////		rectangle = rec;
////
////	}
//	void isIntersectingTest(bool expectedValueSentFromMain) {
//		bool expectedOutput = expectedValueSentFromMain;
//		bool actualOutput;
//		actualOutput = PointOperations::isIntersecting(point, rectangle);
//		cout << actualOutput;
//		if (expectedOutput == actualOutput) {
//			cout << "Working Fine";
//		} else {
//			cout << "Not Working";
//		}
//
//	}
//	void isEqualTest(bool expectedValueSentFromMain) {
//		bool expectedOutput= expectedValueSentFromMain;
//		bool actualOutput;
//		actualOutput = PointOperations::isEqual(point1, point2);
//		cout << actualOutput;
//		if (expectedOutput == actualOutput) {
//			cout << "Working Fine";
//		} else {
//			cout << "Not Working";
//		}
//
//	}
//	void isDisjointTest(bool expectedValueSentFromMain) {
//		bool expectedOutput= expectedValueSentFromMain;
//		bool actualOutput;
//		actualOutput = PointOperations::isDisjoint(point1, point2);
//		cout << actualOutput;
//		if (expectedOutput == actualOutput) {
//			cout << "Working Fine";
//		} else {
//			cout << "Not Working";
//		}
//	}
//	void isWithinTest(bool expectedValueSentFromMain) {
//		bool expectedOutput= expectedValueSentFromMain;
//		bool actualOutput;
//		actualOutput = PointOperations::isWithin(point, rectangle);
//		cout << actualOutput;
//		if (expectedOutput == actualOutput) {
//			cout << "Working Fine";
//		} else {
//			cout << "Not Working";
//		}
//
//	}
//	void isOverlappingTest(bool expectedValueSentFromMain) {
//		bool expectedOutput= expectedValueSentFromMain;
//		bool actualOutput;
//		actualOutput = PointOperations::isOverlapping(point1, point2);
//		cout << actualOutput;
//		if (expectedOutput == actualOutput) {
//			cout << "Working Fine";
//		} else {
//			cout << "Not Working";
//		}
//
//	}
////	void isOverlappingPtRectTest(bool expectedValueSentFromMain) {
////		bool expectedOutput= expectedValueSentFromMain;
////		bool actualOutput;
////		actualOutput = PointOperations::isOverlapping(point1, rectangle);
////		cout << actualOutput;
////		if (expectedOutput == actualOutput) {
////			cout << "Working Fine";
////		} else {
////			cout << "Not Working";
////		}
//
//	}
//	void getDistanceTest(float expectedValueSentFromMain) {
//		float expectedOutput = expectedValueSentFromMain;
//		float actualOutput;
//		actualOutput = PointOperations::getDistance(point1, point2);
//		cout << actualOutput;
//		if (expectedOutput == actualOutput) {
//			cout << "Working Fine";
//		} else {
//			cout << "Not Working";
//		}
//
//	}
//	void getDistancePtRectTest(float expectedValueSentFromMain) {
//		float expectedOutput= expectedValueSentFromMain;
//		float actualOutput;
//		actualOutput = PointOperations::getDistance(point, rectangle);
//		cout << actualOutput;
//		if (expectedOutput == actualOutput) {
//			cout << "Working Fine";
//		} else {
//			cout << "Not Working";
//		}
//
//	}
//
//};
int main() {
    //Point:: pt (1, 2);
	Point point1(31, 4);
	Point point2(1, 3);
	Rectangle rec(2, 4, 4, 6);
    //double actualOutput = PointOperations::getDistance(pt1, pt2);
	cout<<point1.getCoordinates().at(0)<<endl<<point1.getCoordinates().at(1)<<endl
			;
   // cout << actualOutput;
	cout<<"test1"<<boost::geometry::distance(point(point1.getCoordinates().at(0), point1.getCoordinates().at(1)), point(point2.getCoordinates().at(0), point2.getCoordinates().at(1)))<<endl;
cout<< getDistance(point1, point2)<<endl;
	cout<<getDistance(point1, rec);

//	PointOperationsTest pointOperationsTest(pt, pt1, pt2, rec);
//	pointOperationsTest.isIntersectingTest(true);
//	pointOperationsTest.isEqualTest(true);
//	pointOperationsTest.isDisjointTest(true);
//	pointOperationsTest.isWithinTest(true);
//	pointOperationsTest.isOverlappingTest(true);
//	pointOperationsTest.isOverlappingPtRectTest(true);
//	pointOperationsTest.getDistanceTest(20.00);
//	pointOperationsTest.getDistancePtRectTest(20.00);
	return 0;
}
