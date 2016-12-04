// Linear Regression
// Perves Mohammed
// This program will find the line of best fit for any binary response
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    int i,j,k,pairs,xValue;
    cout<<"Enter the no. of data pairs to be entered: ";        //To find the size of arrays
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
    cout<<endl;
    cout<<"S.no"<<setw(10)<<"x"<<setw(20)<<"y(actual)"<<setw(30)<<"y(fitted)" <<setw(40)<<"deviation"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------\n";
    for (i=0; i<pairs; i++)
        cout<<i+1<<"."<<setprecision(12)<<setw(12)<<x[i]<<setprecision(12)<<setw(20)<<y[i]<<setprecision(12)<<setw(30)<<y_fit[i]<<setprecision(12)<<setw(40)<<y[i] - y_fit[i]<<endl; //print a table of x,y(obs.) and y(fit.)
    cout <<"The linear function of the line of best fit is: f(x)= "<<a<<"x + "<<b<<endl;    //print the line of best fit
    cout << "Enter the x-value you would like to substitute to the function: "; //gets input x value to sub in to the function
    cin >> xValue;
    cout << "Your y-value: " << a * xValue + b; // calculates and displays the y-value that is correspondent of the x-value according to the generated function
    return 0;
}
/*
Examples
****************************************************************************
NBA Players Height & Weight
****************************

Birth Rate & Infant Mortality Rate
*************************************************
Country               BR      N/A      N/A    IMR
-------------------------------------------------
Venezuela            46.4     392    0.40    68.5
Mexico               45.7     118    0.61    87.8
Ecuador              45.3      44    0.53   115.8
Colombia             38.6     158    0.53   106.8
Ceylon               37.2      81    0.53    71.6
Puerto Rico          35.0     374    0.37    60.2
Chile                34.0     187    0.30   118.7
Canada               28.3     993    0.19    33.7
United States        24.7    1723    0.12    27.2
Argentina            24.7     287    0.20    62.0
New Zealand          24.4     970    0.19    24.9
Australia            22.7     885    0.12    22.9
Hungary              22.3     200    0.53    65.7
Netherlands          21.7     575    0.14    21.6
Finland              21.6     688    0.34    32.4
Phillipines          21.3      48    0.69   108.7
Ireland              21.2     572    0.49    38.6
Japan                20.8     239    0.42    46.7
Spain                20.3     244    0.48    56.5
France               18.9     472    0.25    44.4
Greece               18.8     134    0.52    47.4
Norway               18.6     633    0.19    21.7
Italy                18.0     295    0.44    55.7
Denmark              17.6     906    0.24    27.1
Switzerland          17.0    1045    0.16    28.5
Belgium              16.7     775    0.10    41.6
West Germany         15.9     619    0.15    44.6
England              15.3     901    0.05    26.1
Sweden               15.0     910    0.24    18.7
Austria              14.8     556    0.22    49.1

Legend
------
BR = Birth Rate
IMR = Infant Mortality Rate
N/A = Not Applicable

References
----------
Source: R. Weintraub (1962). "The Birth Rate and Economic Development:
      An Empirical Study", Econometrica, Vol. 40, #4, pp 812-817.


**********************************************************************
RESULTS
**********************************************************************
Enter the no. of data pairs to be entered:
30

(Birth Rate)
Enter the x-axis values:
46.4
45.7
45.3
38.6
37.2
35
34
28.3
24.7
24.7
24.4
22.7
22.3
21.7
21.6
21.3
21.2
20.8
20.3
18.9
18.8
18.6
18
17.6
17
16.7
15.9
15.3
15
14.8

(Infant Mortality Rate)
Enter the y-axis values:
68.5
87.8
115.8
106.8
71.6
60.2
118.7
33.7
27.2
62
24.9
22.9
65.7
21.6
32.4
108.7
38.6
46.7
56.5
44.4
47.4
21.7
55.7
27.1
28.5
41.6
44.6
26.1
18.7
49.1
S.no         x           y(actual)                     y(fitted)                               deviation
------------------------------------------------------------------------------------------------------------------
1.        46.4                68.5                 96.7748794556                          -28.2748794556
2.        45.7                87.8                  95.342918396                            -7.542918396
3.        45.3               115.8                 94.5246505737                           21.2753494263
4.        38.6               106.8                 80.8186950684                           25.9813049316
5.        37.2                71.6                 77.9547653198                          -6.35476531982
6.          35                60.2                 73.4542999268                          -13.2542999268
7.          34               118.7                 71.4086380005                           47.2913619995
8.        28.3                33.7                 59.7483444214                          -26.0483444214
9.        24.7                27.2                 52.3839492798                          -25.1839492798
10.        24.7                  62                 52.3839492798                           9.61605072021
11.        24.4                24.9                 51.7702484131                          -26.8702484131
12.        22.7                22.9                 48.2926216125                          -25.3926216125
13.        22.3                65.7                 47.4743537903                           18.2256462097
14.        21.7                21.6                 46.2469558716                          -24.6469558716
15.        21.6                32.4                  46.042388916                           -13.642388916
16.        21.3               108.7                 45.4286880493                           63.2713119507
17.        21.2                38.6                 45.2241210938                          -6.62412109375
18.        20.8                46.7                 44.4058570862                           2.29414291382
19.        20.3                56.5                 43.3830223083                           13.1169776917
20.        18.9                44.4                 40.5190925598                           3.88090744019
21.        18.8                47.4                 40.3145256042                           7.08547439575
22.        18.6                21.7                 39.9053916931                          -18.2053916931
23.          18                55.7                 38.6779937744                           17.0220062256
24.        17.6                27.1                 37.8597297668                          -10.7597297668
25.          17                28.5                 36.6323280334                          -8.13232803345
26.        16.7                41.6                 36.0186309814                           5.58136901855
27.        15.9                44.6                 34.3820991516                           10.2179008484
28.        15.3                26.1                 33.1546974182                          -7.05469741821
29.          15                18.7                 32.5410003662                          -13.8410003662
30.        14.8                49.1                 32.1318664551                           16.9681335449
The linear function of the line of best fit is: f(x)= 2.04566502571x + 1.85602366924
Enter the x-value you would like to substitute to the function
                                                          17.12
Your y-value: 36.6323291063
Process returned 0 (0x0)   execution time : 433.396 s
Press any key to continue.
*/
