#include<iostream>
#include<vector>
using namespace std;
int pushElement(vector<double> &vect1,double x,double y,double z)
{
    vect1.push_back(x);
    vect1.push_back(y);
    vect1.push_back(z);   
}
int main(){
    vector<double> vect;
    pushElement(vect,10.666,20.55,30.1);
    cout<<vect.size();
    return 0;
}
    