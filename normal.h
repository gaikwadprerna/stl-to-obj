#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


class Normal
{
public:
    double x, y, z;
    vector<double> vectNormal;
    int normalPos = 0;
    void readNormal();
    void writeNormal(ofstream&);
    void pushElement(vector<double> &vect1,double x,double y,double z);
} ;


void Normal :: pushElement(vector<double> &vect1,double x,double y,double z)
{
    vect1.push_back(x);
    vect1.push_back(y);
    vect1.push_back(z);   
}
void Normal::readNormal()
{
    ifstream if_obj;
    if_obj.open("asciistlcube.stl");
    string s;
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
                    pushElement(vectNormal,x,y,z);
                }
            }
            else
            {
                pushElement(vectNormal,x,y,z);
            }
            normalPos++;
        }       
        if_obj >> s;
    }
}

void Normal::writeNormal(ofstream& of)
{
    
    for (int i = 0; i < vectNormal.size(); i = i + 3)
    {
        of << "vn " << vectNormal[i] << " " << vectNormal[i + 1] << " " << vectNormal[i + 2] << endl;
    }
}