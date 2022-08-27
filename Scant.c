#include <iostream>
#include<math.h>
double arr[100],guess[100],b[100];
double arr_P[100];
int n;
using namespace std;
double f(double x)
{
    double res=arr[n];
    for(int i=n-1; i>=0; i--)
    {
        res=res*x+arr[i];
    }
    return res;
}
void secant(double x1, double x2)
{
    double n = 0, xm, x0, c;
    double e = 0.0001;
    if (f(x1) * f(x2) < 0)
    {
        do
        {
            x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
            c = f(x1) * f(x0);
            x1 = x2;
            x2 = x0;
            n++;
            if (c == 0)
                break;
            cout<<"iteration = "<<n<<" x1 ="<<x1<<" x2 = "<<x2<<" x3 ="<<x0<<endl;
            xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        }
        while (fabs(xm - x0) >= e);
        cout << "Root " << x0 << endl;
    }
    else
        cout << "Can not find a root in the given Interval";
}
double maxRoot()
{
    return -( arr[n-1] / arr[n] );
}
int main()
{
    cout<<"ENTER THE TOTAL NO. OF POWER:::: ";
    cin>>n;
    for(int i=0; i<=n; i++)
    {
        cout<<"x^"<<i<<"::";
        cin>>arr[i];
    }
    cout<<"THE POLYNOMIAL IS ::: ";
    for(int i=n; i>=0; i--)
    {
        cout<<arr[i]<<"x^"<<i<<" ";
        if(i>=0 && arr[i]>=0)cout<<"+";
    }
    cout<<endl;
    for(int i=0; i<2; i++)
    {
        cout<<"INTIAL x"<<i<<"---->";
        cin>>guess[i];
    }
    cout<<endl;
    secant(maxRoot(),guess[1]);
    return 0;
}
