#include<iostream>
#include "header.h"
using namespace std;
int main()
{

vertexAndNormal vertexAndNormalobj;
vertexAndNormalobj.readVertexAndNormal();
vertexAndNormalobj.writeVertexAndNormal();

facet facetObj;
facetObj.readFacet();
facetObj.writeFacet();
return 0;	
}

void vertexAndNormal::readVertexAndNormal()
{
    ifstream if_obj;
    if_obj.open("asciistlcube.stl");
    string s;
  //  double x, y, z;
    while (if_obj)
    {
        if (s == "normal")
        {
            if_obj >> x >> y >> z;
            if (normalPos > 0)
            {
                // cout << "size" << vn.size() << endl;
                int isUnique = 0;
                for (int j = 0; j < vectNormal.size(); j = j + 3)
                {
                    if (vectNormal[j] == x && vectNormal[j + 1] == y && vectNormal[j + 2] == z)
                    {
                        isUnique = 1;
                    }
                }
                if (isUnique == 0)
                {
                    vectNormal.push_back(x);
                    vectNormal.push_back(y);
                    vectNormal.push_back(z);
                }
            }
            else
            {
                vectNormal.push_back(x);
                vectNormal.push_back(y);
                vectNormal.push_back(z);
            }
            normalPos++;
        }
        if (s == "vertex")
        {
            if_obj >> x >> y >> z;
            if (vertexPos > 0)
            {
               // cout << "size" << v.size() << endl;
                int isUnique = 0;
                for (int j = 0; j < vectVertex.size(); j = j + 3)
                {
                    if (vectVertex[j] == x && vectVertex[j + 1] == y && vectVertex[j + 2] == z)
                    {
                        isUnique = 1;
                    }
                }
                if (isUnique == 0)
                {
                    vectVertex.push_back(x);
                    vectVertex.push_back(y);
                    vectVertex.push_back(z);
                }
            }
            else
            {
                vectVertex.push_back(x);
                vectVertex.push_back(y);
                vectVertex.push_back(z);
            }
            vertexPos++;
            // cout << "v"  << " " << x << " " << y << " " << z << endl;
        }
        if_obj >> s;
    }
}


void vertexAndNormal::writeVertexAndNormal()
{
    
    for (int i = 0; i < vectVertex.size(); i = i + 3)
    {
        of << "v " << vectVertex[i] << " " << vectVertex[i + 1] << " " << vectVertex[i + 2] << endl;
    }
    of<<"\n";
    for (int i = 0; i < vectNormal.size(); i = i + 3)
    {
        of << "vn " << vectNormal[i] << " " << vectNormal[i + 1] << " " << vectNormal[i + 2] << endl;
    }
}
