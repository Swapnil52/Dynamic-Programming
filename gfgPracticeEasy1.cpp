//http://www.practice.geeksforgeeks.org/problem-page.php?pid=700373

#include <iostream>
using namespace std;

int maxBooks(int *a, int n, int k)
{
    int dp[n], i;
    dp[0] = (a[0] <= k) ? a[0] : 0;
    for (i = 1; i < n; i++)
    {
        if (a[i] <= k)
        {
            dp[i] = a[i] + dp[i-1];
        }
        else
        {
            dp[i] = 0;
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        max = max >= dp[i] ? max : dp[i];
    }
    return max;
}

int main()
{
    int t, n, k, i;
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int a[n];
        for(i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        cout<<maxBooks(a, n, k)<<"\n";
    }
}