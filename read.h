#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

void pushElement(vector<double> &vect1,double x,double y,double z)
{
    vect1.push_back(x);
    vect1.push_back(y);
    vect1.push_back(z);   
}

void readVertexAndNormal(vector<double> &vectVertexAndNormal,string str)
{
    ifstream if_obj;
    double xPoint,yPoint,zPoint;
    int pos=0;
    if_obj.open("asciistlcube.stl");
    string readString;
    while (if_obj)
    {
        if (readString == str)
        {
            if_obj >> xPoint >> yPoint >> zPoint;
            if (pos > 0)
            {
                int isUnique = 0;
                for (int j = 0; j < vectVertexAndNormal.size(); j = j + 3)
                {
                    if (vectVertexAndNormal[j] == xPoint && vectVertexAndNormal[j + 1] == yPoint && vectVertexAndNormal[j + 2] == zPoint)
                    {
                        isUnique = 1;
                    }
                }
                if (isUnique == 0)
                {
                    pushElement(vectVertexAndNormal,xPoint,yPoint,zPoint);
                }
            }
            else
            {
                pushElement(vectVertexAndNormal,xPoint,yPoint,zPoint);
            }
            pos++;
        }
        if_obj >>readString;
    }
}
