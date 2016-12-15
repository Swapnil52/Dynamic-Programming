//Find the minimum operations (insert, replace, remove) on a string a to convert it into a string b


#include <iostream>
#include <string>
#define ul unsigned long int

using namespace std;

ul minOperations(string a, string b)
{
    ul m = a.length();
    ul n = b.length();
    ul dp[m+1][n+1];
    ul i, j;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
                continue;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
                continue;
            }
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j])) + 1;
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string a = "sunday";
    string b = "saturday";
    cout<<minOperations(a, b);
}