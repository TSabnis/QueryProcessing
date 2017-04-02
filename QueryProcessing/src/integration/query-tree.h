#ifndef HEADERFILES_QUERY_TREE_H_
#define HEADERFILES_QUERY_TREE_H_
#include <string>
#include "../integration/geometry.h"
#include "../integration/geometry-collection.h"

class QueryTree {
public:
	vector<string> root;
	vector<string> leftFilter;
	PointCollection leftDataPoint;
	RectangleCollection leftDataRect;
	vector<string> rightFilter;
	PointCollection rightDataPoint;
	RectangleCollection rightDataRect;
};

#endif