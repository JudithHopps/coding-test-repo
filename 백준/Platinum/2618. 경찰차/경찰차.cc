#include <bits/stdc++.h>
using namespace std;
int n, y[1004], x[1004], w, dp[1004][1004];

int dist(int a, int b)
{
    return abs(y[a] - y[b]) + abs(x[a] - x[b]);
}
int go(int a, int b)
{
    int next = max(a, b) + 1;
    if (next == w + 2)
    {
        return 0;
    }

    int &ret = dp[a][b];
    if (ret != -1)
        return ret;

    return ret = min(go(next, b) + dist(a, next), go(a, next) + dist(b, next));
}
void print()
{
    int a = 0, b = 1;

    for (int i = 2; i < w + 2; i++)
    {
        if (dp[i][b] + dist(a, i) < dp[a][i] + dist(b, i))
        {
            cout << "1\n";
            a = i;
        }
        else
        {
            cout << "2\n";
            b = i;
        }
    }
}
int main()
{

    cin >> n >> w;
    memset(dp, -1, sizeof(dp));

    y[0] = 1, y[1] = n;
    x[0] = 1, x[1] = n;

    for (int i = 2; i < w + 2; i++)
    {
        cin >> y[i] >> x[i];
    }

    cout << go(0, 1) << "\n";

    print();
    return 0;
}