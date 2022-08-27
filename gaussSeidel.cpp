#include<iostream>
#include<iomanip>
#include<cmath>
#include<bits/stdc++.h>
#define siz 20
#define eps 0.005
using namespace std::chrono;
using namespace std;
int n,i,j,k,flag=0,mm=0,t,kk=0;
double a[siz][siz+1];
double x[siz];
double y;
void gaussSeidel()
{
    for (i=0; i<n; i++)
        for (k=i+1; k<n; k++)
            if (abs(a[i][i])<abs(a[k][i]))
                for (j=0; j<=n; j++)
                {
                    double temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
    for(i=0; i<n; i++)
        do
        {
            for (i=0; i<n; i++)
            {
                y=x[i];
                x[i]=a[i][n];
                for (j=0; j<n; j++)
                {
                    if (j!=i)
                        x[i]=x[i]-a[i][j]*x[j];
                } x
                [i]=x[i]/a[i][i];
                if (abs(x[i]-y)<=eps)
                    flag++;
            }
            cout<<"\n";
            mm++;
        }
        while(flag<n);
    cout<<"\n The solution of linear equations is:\n";
    for (i=0; i<n; i++)
        cout<<"x"<<i<<" = "<<x[i]<<endl;
}
void gauss_eliminaion()
{
    for (i=0; i<n; i++) //Pivotisation
        for (k=i+1; k<n; k++)
            if (abs(a[i][i])<abs(a[k][i]))for (j=0; j<=n; j++)
                {
                    double temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
    /* cout<<"\nThe matrix after Pivotisation is:\n";
    for (i=0;i<n;i++) //print the new matrix
    {
    for (j=0;j<=n;j++)
    cout<<a[i][j]<<setw(16);
    cout<<"\n";
    }*/
    for (i=0; i<n-1; i++)
    {
        kk++;
        for (k=i+1; k<n; k++)
        {
            double t=a[k][i]/a[i][i];
            for (j=0; j<=n; j++)
                a[k][j]=a[k][j]-t*a[i][j];
        }
    }
    /* cout<<"\n\nThe matrix after gauss-elimination is as follows:\n";
    for (i=0;i<n;i++) //print the new matrix
    {
    for (j=0;j<=n;j++)
    cout<<a[i][j]<<setw(16);
    cout<<"\n";
    }*/
    for (i=n-1; i>=0; i--) //back-substitution
    {
        x[i]=a[i][n];
        for (j=i+1; j<n; j++)
            if (j!=i)
                x[i]=x[i]-a[i][j]*x[j];
        x[i]=x[i]/a[i][i];
    }
    cout<<"\n The solution of linear equations is:\n";
    for (i=0; i<n; i++)
        cout<<x[i]<<endl;
}
int main()
{
    cout.precision(4);
    cout.setf(ios::fixed);
    cout<<"\nEnter the no. of equations\n";
    cin>>n;
    cout<<"\nEnter the elements of the augmented matrix row-wise:\n";
    for (i=0; i<n; i++)
        for (j=0; j<=n; j++)
            cin>>a[i][j];
    cout<<"\nEnter the initial values of the variables:\n";
    for (i=0; i<n; i++)
        x[i]=0;
    cout<<"Starting of Execution Gauss Elimination Method:"<<endl;
    auto start = std::chrono::high_resolution_clock::now();
    gauss_eliminaion();
    cout<<"End of Execution......."<<endl;
    auto stop = std::chrono::high_resolution_clock::now();
    cout<<"Running Time for Gauss Elimination Method:";
    auto duration = duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time : "<< duration.count() << " microseconds" << endl;
    cout<<"Number of Iterations:"<<kk<<endl;
    cout<<"Starting of Execution Gauss Seidel Method:"<<endl;
    auto start1 = std::chrono::high_resolution_clock::now();
    gaussSeidel();
    cout<<"End of Execution......."<<endl;
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = duration_cast<std::chrono::microseconds>(stop1 - start1);
    cout<<"Running Time for Gauss Seidel Method:";
    cout << "Time : "<< duration1.count() << " microseconds" << endl;
    cout<<"Number of Iterations:"<<mm;
    return 0;
}
