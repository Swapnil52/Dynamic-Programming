//Find the cost of the minimum-cost-path in a nxn cost matrix.

#include <iostream>
using namespace std;

int minCost(int cost[3][3])
{
    
    int dp[3][3], i, j;
    dp[0][0] = cost[0][0];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == 0)
            {
                dp[i][j] = cost[i][j] + dp[i][j-1];
                continue;
            }
            else if (j == 0)
            {
                dp[i][j] = cost[i][j] + dp[i-1][j];
                continue;
            }
            dp[i][j] = cost[i][j] + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
        }
    }
    return dp[2][2];
}

int main()
{
    int cost[3][3] = {
        {
            1, 2, 3
        },
        {
            4, 8, 2
        },
        {
            1, 5, 3
        }
    };
    cout<<minCost(cost)<<"\n";
}