#include<fstream>
#include<iostream>

#include "facet.h"
#include "normal.h"
#include "vertex.h"
#include "read.h"

using namespace std;
ofstream of("cube.obj");

int main()
{
    vertex vertexObj;
   readVertexAndNormal(vertexObj.vectVertex,"vertex");

    Normal normalObj;
   readVertexAndNormal(normalObj.vectNormal,"normal");

    facet facetObj;
    facetObj.readFacet();

    vertexObj.writeVertex(of);
    normalObj.writeNormal(of);
    facetObj.writeFacet(of);

    return 0;
}