#include <string>
#include "geometry.h"

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
