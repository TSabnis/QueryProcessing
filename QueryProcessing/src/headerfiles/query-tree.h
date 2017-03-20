#include <string>
#include "geometry.h"

class QueryTree {
public:
    string* root;
    string* leftFilter;
    GeometryCollection leftData;
    string* rightFilter;
    GeometryCollection rightData;
};
