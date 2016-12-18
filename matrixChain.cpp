//Matrix chain multiplication

#include <iostream>
using namespace std;

int matrix(int *p, int n)
{
    int dp[n][n], i, j, q, k, l;
    for (i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }
    for (l = 2; l < n; l++)
    {
        for (i = 1; i < n-l+1; i++)
        {
            j = i+l-1;
            dp[i][j] = INT_MAX;
            for (k = i; k < j; k++)
            {
                q = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                dp[i][j] = min(q, dp[i][j]);
            }
        }
    }
    return dp[1][n-1];
}

int main()
{
    int p[] = {10, 30, 5, 60};
    cout<<matrix(p, 4);
}
