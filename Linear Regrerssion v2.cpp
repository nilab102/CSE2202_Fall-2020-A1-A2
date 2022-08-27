
#include<stdio.h>
#include<math.h>
double approx_res[100];
float linearRegression(int n, float x[], float y[], float xp)
{
    float sumX = 0;
    float sumX2 = 0;
    float sumY = 0;
    float sumXY = 0;
    float a,b;
    for (int i = 1; i <= n; i++)
    {
        sumX += x[i];
        sumX2 += x[i]*x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
    } b
        = ( n * sumXY - sumX * sumY ) / ( n * sumX2 - sumX * sumX );
    a = ( sumY - b * sumX ) / n;
    return a + b * xp;
}
int main()
{
    int rows;
    float xp;
    printf("Number of inputs: ");
    scanf("%d",&rows);
    float x[rows+1], y[rows+1];
// printf("Input X: ");
    for (int i = 1; i <= rows; i++)
    {
        scanf("%f",&x[i]);
        scanf("%f",&y[i]);
    }
// printf("Input Y: ");
    for (int i = 1; i <= rows; i++)
    { }
// printf("Enter the degree of polynomial to fit: ");
// scanf("%d",&n);
// printf("Enter the non-tabulated value: ");
// scanf("%f",&xp);
//printf("\nx\tInterpolated\tTrue Value\tAbsolute Error\n");
    xp = 1993;
    int count=0;
    while ( xp <= 2013)
    {
        float yp = linearRegression(rows, x, y, xp);
        float tv = cbrtf(xp);
        if(xp==1995)
        {
            printf("Avarage temperature in ");
            printf("%0.0f\t",xp);
            printf("%0.3f\t\n",yp);
            /* printf("%0.3f\t\t",tv);
            printf("%0.3f\n",fabs(yp - tv));*/
        }
        double approx_x,true_x;
        approx_x=linearRegression(rows, x, y, xp);
        approx_res[count]=approx_x;
        count++;
        xp += 1;
    }
    double sam=0;
    for(int i=0; i<rows; i++)
    {
        sam=sam+pow((y[i]-approx_res[i]),2);
        sam=sam/rows;
    }
    printf("Mean Squared Error (MSE)\t\t\t %f\n",sam);
    return 0;
}
