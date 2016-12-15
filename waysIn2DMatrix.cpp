#include <iostream>
using namespace std;

int waysUtil(int n, int dp[100][100], int i, int j)
{
    //check table
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (i == 0 && j == 0)
    {
        return dp[i][j];
    }
    else if (i == 0)
    {
        return waysUtil(n, dp, 0, j-1);
    }
    else if (j == 0)
    {
        return waysUtil(n, dp, i-1, 0);
    }
    return waysUtil(n, dp, i-1, j) + waysUtil(n, dp, i, j-1);
    
}

int ways(int n, int i, int j)
{
    int dp[100][100];
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 1;
    return waysUtil(n, dp, i, j);
}

//Now try it using iteration

unsigned long long int iways(long long int n, long long int i, long long int j)
{
    unsigned long long int dp[n][n], p, q;
    for (p = 0; p < n; p++)
    {
        for (q = 0; q < n; q++)
        {
            dp[p][q] = 0;
            
        }
    }
    for (q = 0; q < n; q++)
    {
        dp[0][q] = 1;
    }
    for (p = 0; p < n; p++)
    {
        dp[p][0] = 1;
    }
    for (p = 1; p < n; p++)
    {
        for (q = 1; q < n; q++)
        {
            dp[p][q] = dp[p-1][q] + dp[p][q-1];
        }
    }
    return dp[i][j];
}


int main()
{
    unsigned long long int n;
    n = 1;
    while(n != -1)
    {
        cin>>n;
        cout<<iways(n, n-1, n-1)<<"\n";
    }
}
