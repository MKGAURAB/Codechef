#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    double a, b, expv;
    int Test;
    cin>>Test;
    while(Test--)
    {
        cin>>a;
        b = 1.0-a;
        expv = 10000.0 + max( (2*b*10000.0)*a-(10000.0*b), (2*a*10000.0)*b - (a*10000.0) );
        printf("%.10lf\n",expv);
    }

    return 0;
}
