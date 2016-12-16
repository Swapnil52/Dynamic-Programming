//Knapsack problem

#include <iostream>
using namespace std;

int knapsack(int *val, int n, int *wt, int w)
{
    
    int dp[1+n][1+w];
    int i, j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], val[i] + dp[i-1][j-wt[i]]);
            }
        }
    }
    return dp[n][w];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = 3;
    cout<<knapsack(val, n, wt, W)<<"\n";
}