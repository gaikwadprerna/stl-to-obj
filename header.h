#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ofstream of("cube.obj");

class vertexAndNormal
{
public:
    double x, y, z;
    vector<double> vectNormal, vectVertex;
    int vertexPos = 0, normalPos = 0;
    void readVertexAndNormal();
    void writeVertexAndNormal();
} ;


class facet
{
public:
    double d1, d2, d3;
    vector<string> vectNormal;
    vector<string> vectVertex;
    void readFacet();
    void writeFacet();
} ;


string mergeStrings1(double d1,double d2,double d3){
            string s1 = to_string(d1);
            string s2 = to_string(d2);
            string s3 = to_string(d3);
            string s4 = s1 + s2 + s3;
            return s4;
}
void facet::readFacet()
{
    ifstream if_obj;
    if_obj.open("asciistlcube.stl");
    string s;
    
    int posNormal=0,posVertex=0;
    while (if_obj)
    {
        if (s == "normal")
        {
        	if_obj>>d1>>d2>>d3; 
            string s4=mergeStrings1(d1,d2,d3); 
          //  string s1 = to_string(d1);
          //  string s2 = to_string(d2);
          //  string s3 = to_string(d3);
          //  string s4 = s1 + s2 + s3;
          int temp=0;
          if(posNormal>0)
          {
          	for(int i=0;i<posNormal;i++)
          	{
			  if(vectNormal[i]==s4){temp=1;}	
			}
			if(temp==0)
			{
				vectNormal.push_back(s4);
				posNormal++;
			}
		  }
		  else
		  {	
          vectNormal.push_back(s4);
          posNormal++;
		  }
            
        }
        if (s == "vertex")
        {
        	if_obj>>d1>>d2>>d3; 
            string s4=mergeStrings1(d1,d2,d3); 
          //  string s1 = to_string(d1);
          //  string s2 = to_string(d2);
          //  string s3 = to_string(d3);
          //  string s4 = s1 + s2 + s3;
          //  cout<<s4<<endl;
          int temp=0;
          if(posVertex>0)
          {
          	for(int i=0;i<posVertex;i++)
          	{
			  if(vectVertex[i]==s4){temp=1;}	
			}
			if(temp==0)
			{
				vectVertex.push_back(s4);
				posVertex++;
			}
		  }
		  else
		  {
          vectVertex.push_back(s4);
          posVertex++;
		  }
		  }
        if_obj >> s;
    }
    if_obj.close();
}

void facet::writeFacet()
{
	ifstream if_obj;
    if_obj.open("asciistlcube.stl");
    string s;
    int posn,posv;
    while (if_obj)
    {
        if (s == "normal")
        {
        	of<<"\nf ";
        	if_obj>>d1>>d2>>d3; 
            string s4=mergeStrings1(d1,d2,d3); 
          //  string s1 = to_string(d1);
          //  string s2 = to_string(d2);
          //  string s3 = to_string(d3);
          //  string s4 = s1 + s2 + s3;
            for(int i=0;i<vectNormal.size();i++)
			{
				if(vectNormal[i]==s4){posn=i+1;}
			}            
        }
        if (s == "vertex")
        {
        	if_obj>>d1>>d2>>d3; 
            string s4=mergeStrings1(d1,d2,d3); 
          //  string s1 = to_string(d1);
          //  string s2 = to_string(d2);
          //  string s3 = to_string(d3);
          //  string s4 = s1 + s2 + s3;
            for(int i=0;i<vectNormal.size();i++)
			{
				if(vectVertex[i]==s4){posv=i+1;}
			}    
			of<<posv<<"///"<<posn<<" ";
		}
        if_obj >> s;
    }
    if_obj.close();
	
}