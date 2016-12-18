//Largest Contiguous Sum

#include <iostream>
using namespace std;

int largestContiguousSum(int *a, int n)
{
    int dp[n];
    dp[0] = a[0] >= 0 ? a[0] : 0;
    int i = 0, m = INT_MIN;
    for (i = 1; i < n; i++)
    {
        dp[i] = (a[i] + dp[i-1]) >= 0 ? a[i] + dp[i-1] : 0;
        m = m < dp[i] ? dp[i] : m;
    }
    return m;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -4};
    cout<<largestContiguousSum(a, 8)<<"\n";
}