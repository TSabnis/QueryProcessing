/*
 * Main.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: tejal
 */

#include <string>
#include <iostream>
#include <vector>
#include "../integration/query-tree.h"

using namespace std;


int main() {



	QueryTree qTree1;
	QueryResult qTree1Result;

	//The query tree root and left and right all is null
	vector<string> null = "";
	PointCollection ptcolNull = "";
	RectangleCollection retcolNull = "";
	PointCollection ptcol;
	RectangleCollection retcol;

	qTree1.setRoot(null);
	qTree1.setLeftFilter(null);
	qTree1.setLeftPoints(ptcolNull);
	qTree1.setLeftRectangles(retcolNull);
	//qTree1.setLeftIndexedObject(null);
	qTree1.setRightFilter(null);
	qTree1.setRightPoints(ptcolNull);
	qTree1.setRightRectangles(retcolNull);
	//qTree1.setRightIndexedObject(null));

	qTree1Result = processQuery(qTree1);
	if (qTree1Result.getResultType() == 0)
		cout<< "Pass Test 1"<<endl;
//---------------------------------------------------------------
	//The return all the points whose distance is less than 5 from Point(0,0)
	qTree1.setRoot(null);
	vector<string> left;
	left.push_back("filterBy");
	left.push_back("distance");
	left.push_back("le");
	left.push_back("5");
	left.push_back("0");
	left.push_back("0");

	//copy(left.begin(),left.end(),qTree1.leftFilter.begin());
	qTree1.setLeftFilter(left);

	PointCollection ptcol;
	for(int i=0;i<4;i++)
		ptcol.insert(Point(i,i));

	qTree1.setLeftPoints(ptcol);

	qTree1.setLeftRectangles(retcolNull);
	//qTree1.setLeftIndexedObject("");
	qTree1.setRightFilter(null);
	qTree1.setRightPoints(ptcolNull);
	qTree1.setRightRectangles(retcolNull);
	//qTree1.setRightIndexedObject("");

	qTree1Result = processQuery(qTree1);

	if (qTree1Result.getResultType() == 3){
		PointPointCollection ppcol = qTree1Result.getPointPointCollection();
		for(int i=0;i<ppcol.getSize();i++)
		{
			cout<< ppcol.getNext(1)<<endl;
		}
	}
	else{
		cout << "Fail Test 2"<<endl;
	}
	//---------------------------------------------------------------
	//The return all the points whose distance is less than 3 from Rectangle(0,0,2,2)
	qTree1.setRoot(null);
	vector<string> left;
	left.push_back("filterBy");
	left.push_back("distance");
	left.push_back("le");
	left.push_back("3");
	left.push_back("0");
	left.push_back("0");
	left.push_back("2");
	left.push_back("2");

	//copy(left.begin(),left.end(),qTree1.leftFilter.begin());
	qTree1.setLeftFilter(left);


	for(int i=0;i<4;i++)
		ptcol.insert(Point(i,i));

	qTree1.setLeftPoints(ptcol);

	qTree1.setLeftRectangles(retcolNull);
	//qTree1.setLeftIndexedObject("");
	qTree1.setRightFilter(null);
	qTree1.setRightPoints(ptcolNull);
	qTree1.setRightRectangles(retcolNull);
	//qTree1.setRightIndexedObject("");

	qTree1Result = processQuery(qTree1);

	if (qTree1Result.getResultType() == 3){
		PointPointCollection ppcol = qTree1Result.getPointPointCollection();
		for(int i=0;i<ppcol.getSize();i++)
		{
			cout<< ppcol.getNext(1)<<endl;
		}
	}
	else{
		cout << "Fail Test 3"<<endl;
	}
	//---------------------------------------------------------------
	//The return all the rectangles whose distance is less than 3 from Point(0,0)
	qTree1.setRoot(null);
	vector<string> left;
	left.push_back("filterBy");
	left.push_back("distance");
	left.push_back("le");
	left.push_back("5");
	left.push_back("0");
	left.push_back("0");

	//copy(left.begin(),left.end(),qTree1.leftFilter.begin());
	qTree1.setLeftFilter(left);
	qTree1.setLeftPoints(ptcolNull);

	for(int i=0;i<4;i++)
		retcol.insert(Rectangle(i,i,i+1,i+1));

	qTree1.setLeftRectangles(retcol);
	//qTree1.setLeftIndexedObject("");
	qTree1.setRightFilter(null);
	qTree1.setRightPoints(ptcolNull);
	qTree1.setRightRectangles(retcolNull);
	//qTree1.setRightIndexedObject("");

	qTree1Result = processQuery(qTree1);

	if (qTree1Result.getResultType() == 3){
		PointPointCollection ppcol = qTree1Result.getPointPointCollection();
		for(int i=0;i<ppcol.getSize();i++)
		{
			cout<< ppcol.getNext(1)<<endl;
		}
	}
	else{
		cout << "Fail Test 4"<<endl;
	}

	//---------------------------------------------------------------
	//The return all the rectangles whose distance is less than 3 from rectangle(0,0,1,1)
	qTree1.setRoot(null);
	vector<string> left;
	left.push_back("filterBy");
	left.push_back("distance");
	left.push_back("le");
	left.push_back("3");
	left.push_back("0");
	left.push_back("0");
	left.push_back("1");
	left.push_back("1");

	//copy(left.begin(),left.end(),qTree1.leftFilter.begin());
	qTree1.setLeftFilter(left);
	qTree1.setLeftPoints(ptcolNull);

	for(int i=0;i<4;i++)
		retcol.insert(Rectangle(i,i,i+2,i+2));

	qTree1.setLeftRectangles(retcol);
	//qTree1.setLeftIndexedObject("");
	qTree1.setRightFilter(null);
	qTree1.setRightPoints(ptcolNull);
	qTree1.setRightRectangles(retcolNull);
	//qTree1.setRightIndexedObject("");

	qTree1Result = processQuery(qTree1);

	if (qTree1Result.getResultType() == 3){
		PointPointCollection ppcol = qTree1Result.getPointPointCollection();
		for(int i=0;i<ppcol.getSize();i++)
		{
			cout<< ppcol.getNext(1)<<endl;
		}
	}
	else{
		cout << "Fail Test 5"<<endl;
	}


}


