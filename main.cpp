#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    int i,j,k,pairs,xValue;
    cout<<"\nEnter the no. of data pairs to be entered:\n";        //To find the size of arrays
    cin>>pairs;
    double x[pairs],y[pairs],a,b;
    cout<<"\nEnter the x-axis values:\n";                //Input x-values for inputted number of pairs
    for (i=0; i<pairs; i++)
        cin>>x[i];
    cout<<"\nEnter the y-axis values:\n";                //Input y-values for inputted number of pairs
    for (i=0; i<pairs; i++)
        cin>>y[i];
    float xsum=0,x2sum=0,ysum=0,xysum=0;                //variables for sums/sigma of xi,yi,xi^2,xiyi etc
    for (i=0; i<pairs; i++)
    {
        xsum=xsum+x[i];                        //calculate sigma(xi)
        ysum=ysum+y[i];                        //calculate sigma(yi)
        x2sum=x2sum+pow(x[i],2);                //calculate sigma(x^2i)
        xysum=xysum+x[i]*y[i];                    //calculate sigma(xi*yi)
    }
    a=(pairs*xysum-xsum*ysum)/(pairs*x2sum-xsum*xsum);            //calculate slope
    b=(x2sum*ysum-xsum*xysum)/(x2sum*pairs-xsum*xsum);            //calculate intercept
    float y_fit[pairs];                        //an array to store the new fitted values of y
    for (i=0; i<pairs; i++)
        y_fit[i]=a*x[i]+b;                    //to calculate y(fitted) at given x points
    cout<<"S.no"<<setw(10)<<"x"<<setw(20)<<"y(actual)"<<setw(30)<<"y(fitted)" <<setw(40)<<"deviation"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------\n";
    for (i=0; i<pairs; i++)
        cout<<i+1<<"."<<setprecision(12)<<setw(12)<<x[i]<<setprecision(12)<<setw(20)<<y[i]<<setprecision(12)<<setw(30)<<y_fit[i]<<setprecision(12)<<setw(40)<<y[i] - y_fit[i]<<endl; //print a table of x,y(obs.) and y(fit.)
    cout <<"The linear function of the line of best fit is: f(x)= "<<a<<"x + "<<b<<endl;    //print the best fit line

    cout << "Enter the x-value you would like to substitute to the function" << endl; //gets input x value to sub in to the function
    cin >> xValue;
    cout << "Your y-value: " << a * xValue + b; // calculates and displays the y-value that is correspondent of the x-value according to the generated function
    return 0;
}
