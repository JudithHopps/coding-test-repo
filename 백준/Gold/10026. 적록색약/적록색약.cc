#include <bits/stdc++.h>
using namespace std;
string str;
int n, a[104][104], visited[104][104], ret1, ret2;
vector<pair<int, int>> v;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};

void dfs(int val, int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
            continue;
        if (a[ny][nx] != val || visited[ny][nx])
            continue;
        dfs(val, ny, nx);
    }
}
int go()
{
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                dfs(a[i][j], i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

void change()
{
    for (auto it : v)
    {
        a[it.first][it.second] = 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            if (str[j] == 'R')
                a[i][j] = 1;
            if (str[j] == 'G')
            {
                a[i][j] = 2;
                v.push_back({i, j});
            }
            if (str[j] == 'B')
                a[i][j] = 3;
        }
    }

    ret1 = go();

    change();

    ret2 = go();

    cout << ret1 << " " << ret2 << "\n";

    return 0;
}