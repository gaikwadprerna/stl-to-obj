#include<fstream>
#include <iostream>
#include <vector>
using namespace std;

class vertex
{
public:
    double x, y, z;
    vector<double> vectVertex;
    int vertexPos = 0;
    void readVertex();
    void writeVertex(ofstream&);
};


void pushElement(vector<double> &vect1,double x,double y,double z)
{
    vect1.push_back(x);
    vect1.push_back(y);
    vect1.push_back(z);   
}

void vertex::readVertex()
{
    ifstream if_obj;
    if_obj.open("asciistlcube.stl");
    string s;
    while (if_obj)
    {
        if (s == "vertex")
        {
            if_obj >> x >> y >> z;
            if (vertexPos > 0)
            {
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
                    pushElement(vectVertex,x,y,z);
                }
            }
            else
            {
                pushElement(vectVertex,x,y,z);
            }
            vertexPos++;
        }
        if_obj >> s;
    }
}


void vertex::writeVertex(ofstream& of)
{
    
    for (int i = 0; i < vectVertex.size(); i = i + 3)
    {
        of << "v " << vectVertex[i] << " " << vectVertex[i + 1] << " " << vectVertex[i + 2] << endl;
    }
    of<<"\n";

}