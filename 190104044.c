#include <iostream>
#include<bits/stdc++.h>
using namespace std;
double FunctionEvaluate(double x)
{
    return exp(x)-4*x;
}
int main()
{
    double Xlower,Xupper,Xroot,prevRoot=0,absErr,relativeErr;
    int i=1;
    Xlower=2;
    Xupper=3;
    string lint="d";
    do
    {
        Xroot=(Xlower+Xupper)/2;//bisection
        if(FunctionEvaluate(Xupper)*FunctionEvaluate(Xroot)<0)
        {
            Xlower=Xroot;
            lint="xLower";
        }
        else
        {
            Xupper=Xroot;
            lint="Xupper";
        }
        absErr= fabs(Xroot-prevRoot);
        relativeErr= fabs(absErr/Xroot);
        cout<<"No of iertation - "<<i<<" | Approx root "<< Xroot<<" | Absoulate eror -
            "<<absErr<<" | Relative eror - "<<relativeErr<<" | Change of limit
            -"<<lint<<setprecision(6)<<endl;
            i++;
        prevRoot=Xroot;
    }
    while(fabs(FunctionEvaluate(Xroot))>= 0.00001);
    return 0;
}
