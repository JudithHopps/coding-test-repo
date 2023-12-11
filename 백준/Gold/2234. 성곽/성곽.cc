#include <bits/stdc++.h>
using namespace std;
int n, m, a[54][54], cnt, mx, ret, visited[54][54], room[54];
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

bool ch(int i, int val)
{
    if (i == 0 && (val & 4))
        return true;
    else if (i == 1 && (val & 1))
        return true;
    else if (i == 2 && (val & 8))
        return true;
    else if (i == 3 && (val & 2))
        return true;
    return false;
}
int dfs(int y, int x, int val)
{
    visited[y][x] = val;
    int sum = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if (visited[ny][nx])
            continue;
        if (ch(i, a[y][x]))
        {
            continue;
        }
        sum += dfs(ny, nx, val);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int now = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                room[now] = dfs(i, j, now);
                mx = max(mx, room[now]);
                now++;
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << now - 1 << "\n"
         << mx << "\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] != visited[i][j + 1])
            {
                ret = max(room[visited[i][j]] + room[visited[i][j + 1]], ret);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] != visited[i + 1][j])
            {
                ret = max(room[visited[i][j]] + room[visited[i + 1][j]], ret);
            }
        }
    }

    cout << ret << "\n";
    return 0;
}