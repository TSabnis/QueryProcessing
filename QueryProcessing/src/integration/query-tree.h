#include "spatial-index-interface.h"
#include <vector>
#include <string>

using namespace std;

class QueryTree {
    vector<string> root;
    vector<vector<string>> leftBranch;
    PointCollection leftDataPoint;
    RectangleCollection leftDataRect;
    vector<vector<string>> rightBranch;
    PointCollection rightDataPoint;
    RectangleCollection rightDataRect;
    SpatialIndexInterface rightIndexedObject;
	SpatialIndexInterface leftIndexedObject;

public:
    QueryTree();
    void setRoot(vector<string>);
    void setLeftFilter(vector<vector<string>>);
    void setLeftPoints(PointCollection);
    void setLeftRectangles(RectangleCollection);
    void setLeftIndexedObject(SpatialIndexInterface);
    void setRightFilter(vector<vector<string>>);
    void setRightPoints(PointCollection);
    void setRightRectangles(RectangleCollection);
    void setRightIndexedObject(SpatialIndexInterface);
};
