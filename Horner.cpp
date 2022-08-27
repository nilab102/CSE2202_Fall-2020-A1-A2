#include<bits/stdc++.h>
#include <math.h>
using namespace std;
int degree, itr = 0, deg1, r = 0;
double e, q[100],a[100], a0, a1;
int initial;
double horner(double n)
{
    double p[100];
    p[deg1] = q[deg1];
    for(int i = deg1; i > 0; i--)
    {
        p[i-1] = p[i]*n + q[i-1]; // honers equation
    }
    return p[0];
}
double difHorner(double x)
{
    double p1[100], d[100];
    for(int i = 1; i <= deg1; i++)
    {
        d[i-1] = q[i]*i;
    }
    p1[deg1 - 1] = d[deg1 - 1];
    for(int i = deg1-1; i > 0; i--)
    {
        p1[i-1] = p1[i]*x + d[i-1];
    }
    return p1[0];
}
double f(double x)
{
    return ((x*x*x*x*x)-(5*x*x*x*x)-(35*x*x*x)+(125*x*x)+(194*x)-280);
}
double der_f(double x)
{
    return ((5*x*x*x*x)-(20*x*x*x)-(105*x*x)+(250*x)+194);
}
int ConditionNumber(double x)
{
    double condi = ((x*der_f(x))/(f(x)));
    return condi;
}
void syntheticDivision(double x)
{
    q[deg1] = 0;
    for(int i = deg1; i > 0; i--)
    {
        q[i-1] = a[i] + q[i]*x;
    }
    for(int i = deg1; i > -1; i--)
    {
        a[i] = q[i];
    }
    a0 = a[0];
    a1 = a[1];
}
double err(double a)
{
    return fabs(horner(a));
}
float maxRoot()
{
    return -(a[degree-1]/a[degree]);
}
void newton(double a)
{
    double f0, x0, fr, xr,fb;
    x0 = a; //initialize
    f0 = horner(x0);
    double condi = ConditionNumber(initial);
    if(condi>1)
    {
        cout<<"System is ill Condition"<<endl;
    }
    else
    {
        cout<<"System is Well Condition"<<endl;
        if(difHorner(x0) == 0)
        {
            cout<<"Insufficient root ";
            return;
        }
        while(deg1 > 1)
        {
            while(true)
            {
                itr++;
                f0 = horner(x0);
                fb = difHorner(x0);
                xr = x0 - (f0/fb);
                if(f0 == 0)
                {
                    return; // root
                }
                x0 = xr;
                if(fabs(horner(xr)) < 0.001)
                {
                    cout<<"itr "<<r++<<" Root "<<r<<":";
                    cout<<" "<<xr<<endl;
                    break;
                }
                else
                {
                    x0 = xr;
                }
            }
            cout<<"At order "<<deg1<<" the Root is"<<xr<<" Relative eror
                "<<fabs(horner(xr))<<"iteration is "<<itr<<" The root is not real root"<<endl;
                syntheticDivision(xr);
            deg1--;
        }
        double root1 = -a0/a1;
    }
}
int main()
{
    double root;
    cout<<"Enter the degree of the equation: ";
    cin>>degree;
    deg1 = degree;
    cout<<endl;
    cout<<"Enter the coefficients of the equation: ";
    for(int i = degree; i > -1; i--)
    {
        cin>>a[i];
        q[i] = a[i];
    }
    cout<<endl;
    float croot=maxRoot();
    cout<<"Largest possible root is"<<croot;
    newton(croot);
    cout<<endl;
    cout<<"there are "<< degree<< "Roots for the given polynomial";
    return 0;
}
