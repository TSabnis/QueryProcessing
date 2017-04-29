#ifndef INTEGRATION_HELPER_H
#define INTEGRATION_HELPER_H

#ifndef QUERY_PROCESSING_H
#include "query-processing.h"
#endif

#ifndef CATALOG_H
#include "catalog.h"
#endif

#include "../data-partitioning-indexing/data-indexing.h"

#ifndef IN_MEMORY_SPATIAL_DB_SPATIALINDEXIMPL_H
#include "../spatial-partitioning-indexing/SpatialIndexImpl.h"
#endif

#include <vector>
#include <string.h>

int get_geom_type_from_string(string geom) {
    if(geom.compare("POINT") == 0) return 1;
    if(geom.compare("RECTANGLE") == 0) return 2;
    cout << "Invalid Parameter for geometry type.\n"; 
    return -1;
}

bool is_param_sufficient(vector<string> tokens, int required_params) {
    if(tokens.size() < required_params) {
        cout << "Insufficient Parameters\n";   
        return false;
    }
    return true;
}

vector<string> split(string str, string sep) {
    size_t pos = 0;
    string token;
    vector<string> arr;
    while ((pos = str.find(sep)) != string::npos) {
        token = str.substr(0, pos);
        str.erase(0, pos + sep.length());
        arr.push_back(token);
    }
    arr.push_back(str);
    return arr;
}

vector<vector<string> > get_predicates_from_string(string predicates) {
    vector<string> left_params = split(predicates, "|");
    vector<vector<string> > predicate_vector;
    for(int i=1; i< left_params.size(); i++) {
        predicate_vector.push_back(split(left_params[i], ":"));   
    }
    
    return predicate_vector;
}


void print_query_result(QueryResult resultset) {
    int resultType = resultset.getResultType();
    cout << "Result Type: " << resultType << endl;
    if (resultType == TYPE_POINT) {      
        PointCollection pc = resultset.getPointCollection(); 
        int size = pc.getSize();
        cout << "ResultSet size: " << size << endl;
                for (int i=0; i< pc.getSize(); i++) {
            vector<Point> point = pc.getNext(1);
            vector<float> coords = point[0].getCoordinates();
            cout << "[(" << coords[0] << ", " << coords[1] << ")]" << endl;
        }
    } else if (resultType == TYPE_RECTANGLE) {      
        RectangleCollection rc = resultset.getRectangleCollection(); 
        int size = rc.getSize();
        cout << "ResultSet size: " << size << endl;
        for (int i=0; i < size; i++) {
            vector<Rectangle> rectangle = rc.getNext(1);
            vector<float> coords = rectangle[0].getCoordinates();
            cout << "[(" << coords[0] << ", " << coords[1] << "), (" << coords[2] << ", " << coords[3] << ")]" << endl;
        }
    } else if (resultType == TYPE_POINTPOINT) {      
        PointPointCollection ppc = resultset.getPointPointCollection(); 
        int size = ppc.getSize();
        cout << "ResultSet size: " << size << endl;
        for (int i=0; i< ppc.getSize(); i++) {
            vector<PointPoint> pointPoint = ppc.getNext(1);
            vector<float> coords = pointPoint[0].getCoordinates();
            cout << "[(" << coords[0] << ", " << coords[1] << "), (" << coords[2] << ", " << coords[3] << ")]" << endl;
        }
    } else if (resultType == TYPE_POINTRECTANGLE) {      
        PointRectangleCollection prc = resultset.getPointRectangleCollection(); 
        int size = prc.getSize();
        cout << "ResultSet size: " << size << endl;
        for (int i=0; i< prc.getSize(); i++) {
            vector<PointRectangle> pointRectangle = prc.getNext(1);
            vector<float> coords = pointRectangle[0].getCoordinates();
            cout << "[ [(" << coords[0] << ", " << coords[1] << "), [(" 
                << coords[2] << ", " << coords[3] << "), ("
                << coords[4] << ", " << coords[5] << ")] ]" << endl;
        }
    } else if (resultType == TYPE_RECTANGLERECTANGLE) {      
        RectangleRectangleCollection rrc = resultset.getRectangleRectangleCollection(); 
        int size = rrc.getSize();
        cout << "ResultSet size: " << size << endl;
        for (int i=0; i< rrc.getSize(); i++) {
            vector<RectangleRectangle> rectangleRectangle = rrc.getNext(1);
            vector<float> coords = rectangleRectangle[0].getCoordinates();
            cout << "[ [(" << coords[0] << ", " << coords[1] << "), (" << coords[2] << ", " << coords[3] << ")], " 
                << "[(" << coords[4] << ", " << coords[5] << "), (" << coords[6] << ", " << coords[7] << ")] ]"<< endl;
        }
    } else {
        cout << "ERROR: Unknown Collection Type." << endl;
    }
}

int getCollectionStructureFromString(string collection_structure) {
	if(collection_structure.compare("sortedX") == 0) {
		return COLLECTION_STRUCT_SORTEDX;
	} else if(collection_structure.compare("sortedY") == 0) {
		return COLLECTION_STRUCT_SORTEDY;
	} else if(collection_structure.compare("hilbert") == 0) {
		return COLLECTION_STRUCT_HILBERT;
	} else {
		return COLLECTION_STRUCT_UNSORTED;
	} 
}

void processSpatialIndexQuery(vector<string> query_tokens) {
	SpatialIndexInterface* sp = new SpatialIndexImpl();
	if(query_tokens[2].compare("POINT") == 0) {
		PointCollection* pc = Catalog::Instance()->getPointCollectionByName(query_tokens[3], query_tokens[4]);
		sp->createIndex(*pc);
		CatalogItem* ci = Catalog::Instance()->getCatalogItem(query_tokens[3], query_tokens[4]);
		ci->addSpatialIndex(sp);
	} else if(query_tokens[2].compare("RECTANGLE") == 0) {
		RectangleCollection* rc = Catalog::Instance()->getRectangleCollectionByName(query_tokens[3], query_tokens[4]);
		sp->createIndex(*rc);
		CatalogItem* ci = Catalog::Instance()->getCatalogItem(query_tokens[3], query_tokens[4]);
		ci->addSpatialIndex(sp);
	} else {
		cout << "Invalid data type";
	}
}

void processDataIndexQuery(vector<string> query_tokens) {
	SpatialIndexInterface* sp = new DataIndexingWrapper();
    if(query_tokens[2].compare("POINT") == 0) {
        PointCollection* pc = Catalog::Instance()->getPointCollectionByName(query_tokens[3], query_tokens[4]);
        sp->createIndex(*pc);
        CatalogItem* ci = Catalog::Instance()->getCatalogItem(query_tokens[3], query_tokens[4]);
        ci->addDataIndex(sp);
    } else if(query_tokens[2].compare("RECTANGLE") == 0) {
        RectangleCollection* rc = Catalog::Instance()->getRectangleCollectionByName(query_tokens[3], query_tokens[4]);
        sp->createIndex(*rc);
        CatalogItem* ci = Catalog::Instance()->getCatalogItem(query_tokens[3], query_tokens[4]);
        ci->addDataIndex(sp);
    } else {
        cout << "Invalid data type";
    }
}

void processLoadQuery(vector<string> query_tokens) {
	if(is_param_sufficient(query_tokens, 6)) { 
        int collection_structure = getCollectionStructureFromString(query_tokens[5]);
        bool status = loadData(query_tokens[2], query_tokens[3], get_geom_type_from_string(query_tokens[1]), query_tokens[4], collection_structure);                 
        if(status) {
	        cout << "Loaded " << query_tokens[1] << " data collection into " << query_tokens[2] << "." << query_tokens[3] <<
	         " from " << query_tokens[4] << endl; 
	        cout << "The Catalog now has " << Catalog::Instance()->getCatalogSize() << " item(s)." << endl;
        }        
    }
}

void processIndexQuery(vector<string> query_tokens) {
	if(is_param_sufficient(query_tokens, 3)) {
        if(query_tokens[1].compare("SPATIAL-INDEX") == 0) {
            processSpatialIndexQuery(query_tokens);
        } else if(query_tokens[1].compare("DATA-INDEX") == 0) {
            processDataIndexQuery(query_tokens);
        } else {
            cout << "Invalid index type.\n";                             
        }
    }
}

void processInsertQuery(vector<string> query_tokens) {
	if(query_tokens[1].compare("POINT") == 0) {
        PointCollection* pc = Catalog::Instance()->getPointCollectionByName(query_tokens[2], query_tokens[3]);
        Point* p = new Point(stof(query_tokens[4]), stof(query_tokens[5])); 
        pc->insert(*p);
        cout << "Record inserted." << endl << "The size of the collection is now " << pc->getSize() << "." << endl;
    } else if(query_tokens[1].compare("RECTANGLE") == 0) {
        RectangleCollection* rc = Catalog::Instance()->getRectangleCollectionByName(query_tokens[2], query_tokens[3]);
        Rectangle* r = new Rectangle(stof(query_tokens[4]), stof(query_tokens[5]), stof(query_tokens[6]), stof(query_tokens[7])); 
        rc->insert(*r);
        cout << "Record inserted." << endl << "The size of the collection is now " << rc->getSize() << "." << endl;
    } else {
        cout << "Invalid data types.";
    }
}

char getRootType(string rootType) {
    if(rootType.compare("distanceJoin") == 0) {
        return DISTANCE_JOIN;
    } else if(rootType.compare("rangeJoin") == 0) {
        return RANGE_JOIN;
    } else if(rootType.compare("knnJoin") == 0) {
        return KNN_JOIN;
    } 
    return NO_JOIN;
}

void processSelectQuery(vector<string> query_tokens) {
	QueryTree* qTree = new QueryTree();
    QueryResult* qResult = new QueryResult();
    QueryProcessing* qProcess = new QueryProcessing();

    string query_param = query.substr(7);
    
    int left_param_end = query_param.find("]"); 
    string left_branch = query_param.substr(1, left_param_end-1);  
    vector<vector<string> > left_filter_param = get_predicates_from_string(left_branch);                       
    vector<string> left_collection_details = split(left_branch.substr(0, left_branch.find("|")), " ");
    if(left_collection_details[0].compare("POINT") == 0) {
        PointCollection* left_pc = Catalog::Instance()->getPointCollectionByName(left_collection_details[1], left_collection_details[2]);
        qTree->setLeftPoints(*left_pc);
    } else {
        RectangleCollection* left_rc = Catalog::Instance()->getRectangleCollectionByName(left_collection_details[1], left_collection_details[2]);
        qTree->setLeftRectangles(*left_rc);
    }
    
    qTree->setLeftFilter(left_filter_param);
    

    int root_param_end = query_param.substr(left_param_end+3).find("]");            
    string root = query_param.substr(left_param_end+3, root_param_end);
    vector<string> root_filter_param = split(root, ":");
    
    qTree->setRootType(getRootType(root_filter_param[0]));
    if(root_filter_param.size() > 1) {
        qTree->setRootParam(stofroot_filter_param[1]);
    }

    int right_param_end = query_param.substr(left_param_end+root_param_end+6).find("]"); 
    string right_branch = query_param.substr(left_param_end+root_param_end+6, right_param_end);
    vector<vector<string> > right_filter_param = get_predicates_from_string(right_branch);
    if(right_branch.compare("|") != 0 && right_branch.compare("") != 0 ) {
        vector<string> right_collection_details = split(right_branch.substr(0, right_branch.find("|")), " ");
        if(right_collection_details[0].compare("POINT") == 0) {
            PointCollection* right_pc = Catalog::Instance()->getPointCollectionByName(right_collection_details[1], right_collection_details[2]);
            qTree->setRightPoints(*right_pc);
        } else {
            RectangleCollection* right_rc = Catalog::Instance()->getRectangleCollectionByName(right_collection_details[1], right_collection_details[2]);
            qTree->setRightRectangles(*right_rc);
        }                
        qTree->setRightFilter(right_filter_param);
    }            
    print_query_result(qProcess->processQuery(*qTree));
}
#endif