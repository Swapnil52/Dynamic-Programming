//Longest Bitonic Sequence

#include <iostream>
using namespace std;

int lbs(int *a, int n)
{
    
    //first solve for lis
    int dp1[n];
    dp1[0] = 1;
    int i;
    for (i = 1; i < n; i++)
    {
        if (a[i] < a[i-1])
        {
            dp1[i] = dp1[i-1];
        }
        else
        {
            dp1[i] = 1 + dp1[i-1];
        }
    }
    //Then solve for lds
    int dp2[n];
    dp2[n-1] = 1;
    for (i = n-2; i >= 0; i--)
    {
        if (a[i] < a[i+1])
        {
            dp2[i] = dp2[i+1];
        }
        else
        {
            dp2[i] = 1 + dp2[i+1];
        }
    }
    int max = 0;
    for (i = 0; i < n; i++)
    {
        max = (max >= dp1[i]+dp2[i]-1) ? max : dp1[i]+dp2[i]-1;
    }
    return max;
}

int main()
{
    int a[] = {80, 60, 30, 40, 20, 10};
    cout<<lbs(a, 6)<<"\n";
}