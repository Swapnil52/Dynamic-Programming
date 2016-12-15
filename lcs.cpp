#include <iostream>
#include <string>
using namespace std;

int lcs(string a, string b)
{
    int i, j, m;
    int lcs[a.length()+1][b.length()+1];
    for (i = 0; i <= a.length(); i++)
    {
        lcs[i][0] = 0;
    }
    for (j = 0; j <= b.length(); j++)
    {
        lcs[0][j] = 0;
    }
    m = 0;
    for (i = 1; i <= a.length(); i++)
    {
        for (j = 1; j <= b.length(); j++)
        {
            if (a[i] == b[j])
            {
                lcs[i][j] = 1 + lcs[i-1][j-1];
            }
            else
            {
                lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
            }
            m = m <= lcs[i][j] ? m : lcs[i][j];
        }
    }
    return lcs[a.length()][b.length()];
}

int main()
{
    string a = "BDCABA";
    string b = "ABCDAB";
    cout<<lcs(a, b);
}