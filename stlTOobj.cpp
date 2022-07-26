#include<fstream>
#include<iostream>

#include "facet.h"
#include "normal.h"
#include "vertex.h"

using namespace std;
ofstream of("cube.obj");

int main()
{
    vertex vertexObj;
    vertexObj.readVertex();

    Normal normalObj;
    normalObj.readNormal();

    facet facetObj;
    facetObj.readFacet();

    vertexObj.writeVertex(of);
    normalObj.writeNormal(of);
    facetObj.writeFacet(of);

    return 0;
}