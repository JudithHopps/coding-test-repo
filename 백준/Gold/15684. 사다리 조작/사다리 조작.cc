#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int ret = INF, n, m, h, a, b, visited[34][34];

bool check()
{
    for (int k = 1; k <= n; k++)
    {
        int now = k;

        for (int i = 1; i <= h; i++)
        {
            if (visited[i][now - 1])
                now--;
            else if (visited[i][now])
                now++;
        }
        if (now != k)
            return false;
    }
    return true;
}
void go(int start, int cnt)
{
    if (cnt > 3 || cnt > ret)
        return;

    if (check())
    {
        ret = min(ret, cnt);
        return;
    }

    for (int i = start; i <= h; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1])
                continue;
            visited[i][j] = 1;
            go(i, cnt + 1);
            visited[i][j] = 0;
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> h;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        visited[a][b] = 1;
    }

    go(1, 0);

    cout << (ret == INF ? -1 : ret) << "\n";

    return 0;
}