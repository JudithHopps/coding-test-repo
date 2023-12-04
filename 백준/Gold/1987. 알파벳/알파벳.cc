#include <bits/stdc++.h>
using namespace std;
int visited[100], r, c, a[24][24], ret;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

void dfs(int y, int x, int cnt)
{
    if (cnt >= r * c)
    {
        ret = cnt;
        return;
    }
    ret = max(ret, cnt);

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= r || nx >= c)
            continue;
        if (visited[a[ny][nx]])
            continue;
        visited[a[ny][nx]] = 1;
        dfs(ny, nx, cnt + 1);
        visited[a[ny][nx]] = 0;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c - 'A';
        }
    }
    visited[a[0][0]] = 1;
    dfs(0, 0, 1);

    cout << ret << "\n";
    return 0;
}