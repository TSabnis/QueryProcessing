#ifndef HEADERFILES_QUERY_TREE_H_
#define HEADERFILES_QUERY_TREE_H_
#include <string>
#include "../integration/geometry.h"
#include "../integration/geometry-collection.h"

#include "spatial-index-interface.h"


class QueryTree {
    vector<string> root;
    vector<string> leftFilter;
    PointCollection leftDataPoint;
    RectangleCollection leftDataRect;
    vector<string> rightFilter;
    PointCollection rightDataPoint;
    RectangleCollection rightDataRect;
    SpatialIndexInterface rightIndexedObject;
	SpatialIndexInterface leftIndexedObject;

public:
    QueryTree();
    void setRoot(vector<string>);
    void setLeftFilter(vector<string>);
    void setLeftPoints(PointCollection);
    void setLeftRectangles(RectangleCollection);
    void setLeftIndexedObject(SpatialIndexInterface);
    void setRightFilter(vector<string>);
    void setRightPoints(PointCollection);
    void setRightRectangles(RectangleCollection);
    void setRightIndexedObject(SpatialIndexInterface);
};

#endif