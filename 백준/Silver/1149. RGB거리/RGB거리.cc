#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321, m = 3;
int n, a[1004][m], dp[1004][m], ret = INF;

int go(int idx, int now)
{
    if (idx == n)
    {
        return 0;
    }
    int &ret = dp[idx][now];
    if (ret)
        return ret;
    ret = INF;

    for (int i = 0; i < m; i++)
    {
        if (now == i)
            continue;
        ret = min(ret, go(idx + 1, i) + a[idx][i]);
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        go(0, i);
    }

    for (int i = 0; i < m; i++)
    {
        ret = min(ret, dp[0][i]);
    }

    cout << ret << "\n";
    return 0;
}