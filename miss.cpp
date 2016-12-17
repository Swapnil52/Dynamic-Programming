//Maximum Sum Increasing Subsequence

#include <iostream>
using namespace std;

int miss(int *a, int n)
{
    
    int dp[n], i, j, m;
    dp[0] = a[0];
    for (i = 1; i < n; i++)
    {
        
        if (a[i] >= a[i-1])
        {
            dp[i] = a[i] + dp[i-1];
        }
        else if (a[i] < a[i-1])
        {
            m = 0;
            for (j = 0; j < i; j++)
            {
                if (a[i] >= a[j])
                {
                    m = m >= dp[j] ? m : dp[j];
                }
            }
            dp[i] = a[i] + m;
        }
        
    }
    m = 0;
    for (i = 0; i < n; i++)
    {
        m = m >= dp[i] ? m : dp[i];
    }
    return m;
}

int main()
{
    int a[] = {1, 101, 2, 3, 100, 4, 5};
    cout<<miss(a, 7)<<"\n";
}