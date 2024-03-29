//
// Created by ravichandran on 18/03/17.
//

#ifndef IN_MEMORY_SPATIAL_DB_PRQUADTREE_H
#define IN_MEMORY_SPATIAL_DB_PRQUADTREE_H

#include "quadTreeLib.h"
#include "prQuadNode.h"

class prQuadTree
{

private:
    qPoint XY_POINT;
    qBoundingBox RANGE;

    prQuadNode *root;

public:

    prQuadTree(){}
    prQuadTree(float originX, float originY, float width, float height, int leafCapacity) {
        float x = originX - width/2;
        float y = originY - height/2;
        qPoint *xyPoint = new qPoint(x,y);
        qBoundingBox *QBB = new qBoundingBox(xyPoint,width,height);
        root = new prQuadNode( *QBB, leafCapacity);
    }

    prQuadTree(float width, float height, int leafCapacity) {
        float x = 0 - width/2;
        float y = 0 - height/2;
        qPoint *xyPoint = new qPoint(x,y);
        qBoundingBox *QBB = new qBoundingBox(xyPoint,width,height);
        root = new prQuadNode( *QBB , leafCapacity);
    }

    prQuadTree(qBoundingBox *qbb, int leafCapacity) {
        root = new prQuadNode( *qbb , leafCapacity);
    }

    prQuadNode* getRoot() {
        return root;
    }

    bool insert(qPoint *xyPoint) {

        return (*root).insert(xyPoint);
    }

    bool insert(float x, float y) {
        qPoint *xyPoint = new qPoint(x,y);

        return (*root).insert(xyPoint);
    }

    bool insert(float x, float y, int id) {
        qPoint *xyPoint = new qPoint(x,y,id);

        return (*root).insert(xyPoint);
    }

    void deleteRoot()
    {
        if(root == NULL) return;

        root->deleteNode();

    }


    void print(string prefix = "", bool emptyLine = false)
    {
        if(emptyLine) cout<<endl;
        cout<<prefix<< "Root Node | ";
        if(root!=NULL)
        {
            print(root,"* ",true);
        }


    }

    void print(prQuadNode *node, string prefix = "", bool emptyLine = false)
    {
        if(node!=NULL)
        {
//            if(node->qbb.getMinX()>=0 && node->qbb.getMinY()>=0)
//            {
//                node->print(prefix,true);
//            }
            node->print(prefix,true);

            if(node->prqnNE != NULL && node->prqnNW != NULL && node->prqnSE != NULL && node->prqnSW != NULL)
            {
                prefix += "\t";
                print(node->prqnNW,prefix + " | NW |",true);
                print(node->prqnNE,prefix + " | NE |",true);
                print(node->prqnSW,prefix + " | SW |",true);
                print(node->prqnSE,prefix + " | SE |",true);

            }
        }


    }

    vector<qPoint> queryRange(float x, float y, float width, float height) {
        vector<qPoint> vQPoint;
        if (root == NULL)
            return vQPoint;

        XY_POINT.set(x,y);
        RANGE.set(&XY_POINT,width,height);

        vector<qPoint> pointsInRange;
        root->queryRange(RANGE,pointsInRange);
        return pointsInRange;
    }

};



#endif //IN_MEMORY_SPATIAL_DB_PRQUADTREE_H
