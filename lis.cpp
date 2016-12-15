#include <iostream>
using namespace std;

int lis(int *a, int n)
{
    
    int dp[n], i, j, max;
    dp[0] = 1;
    
    for (i = 1; i < n; i++)
    {
        max = 0;
        for (j = 0; j < i; j++)
        {
            if (a[i] >= a[j] && dp[j] >= max)
            {
                max = dp[j];
            }
        }
        dp[i] = 1 + max;
    }
    max = 0;
    for (i = 0; i < n; i++)
    {
        max = max >= dp[i] ? max : dp[i];
    }
    return max;
}


int main()
{
    int a[] = {3, 10, 2, 1, 20};
    cout<<lis(a, 5);
}