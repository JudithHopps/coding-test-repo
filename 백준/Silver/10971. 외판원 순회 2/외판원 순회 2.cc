#include <bits/stdc++.h>
using namespace std;
// 외순환 TSP
const int INF = 987654321;
int n, a[20][20], dp[20][1 << 20];

int tsp(int here, int visited)
{
    if (visited == (1 << n) - 1)
    {
        return a[here][0] ? a[here][0] : INF;
    }
    int &ret = dp[here][visited];
    if (ret != -1)
        return ret;
    ret = INF;
    for (int i = 0; i < n; i++)
    {
        if (a[here][i] == 0)
            continue;
        if (visited & (1 << i))
            continue;

        ret = min(ret, tsp(i, visited | (1 << i)) + a[here][i]);
    }
    return ret;
}
int main()
{

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << tsp(0, 1) << "\n";

    return 0;
}