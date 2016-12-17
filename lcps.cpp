#include <iostream>
#include <string>
using namespace std;

int lcpsRecursion(string a, int i, int j)
{
    if (i == j)
    {
        return 1;
    }
    else if (i == j-1)
    {
        if (a[i] == a[j])
        {
            return 2;
        }
        return 1;
    }
    else if (a[i] == a[j])
    {
        return 2 + lcpsRecursion(a, i+1, j-1);
    }
    return max(lcpsRecursion(a, i+1, j), lcpsRecursion(a, i, j-1));
}

int lcps(string a)
{
    string b = a;
    reverse(b.begin(), b.end());
    int n = int(a.length()), i, j;
    int dp[n+1][n+1];
    for (i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n-1][n-1];
}

int main()
{
    cout<<lcpsRecursion("geekees", 0, 6)<<"\n";
    cout<<lcps("geekeekasds")<<"\n";
}