#include "query-tree.h"
#include "../integration/geometry.h"
#include "../integration/geometry-collection.h"

class QueryResult {
    int resultType;
    PointCollection pointCollection;
    RectangleCollection rectangleCollection;
    PointPointCollection pointPointCollection;
    RectangleRectangleCollection rectangleRectangleCollection;
    PointRectangleCollection pointRectangleCollection;
    bool status;    
public:
        QueryResult(int, PointCollection);
        QueryResult(int, RectangleCollection);
        QueryResult(int, PointPointCollection);
        QueryResult(int, RectangleRectangleCollection);
        QueryResult(int, PointRectangleCollection);
	QueryResult(int, bool); 
};

QueryResult processQuery(QueryTree);
