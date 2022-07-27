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
   // void readVertex();
    void writeVertex(ofstream&);
};



void vertex::writeVertex(ofstream& of)
{
    
    for (int i = 0; i < vectVertex.size(); i = i + 3)
    {
        of << "v " << vectVertex[i] << " " << vectVertex[i + 1] << " " << vectVertex[i + 2] << endl;
    }
    of<<"\n";

}