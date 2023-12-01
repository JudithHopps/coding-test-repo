#include <bits/stdc++.h>
using namespace std;
int n, l, h, a[54][54], visited[54][54], cnt, sum = 0;
vector<pair<int, int>> v;
bool flag = 0;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

void dfs(int y, int x)
{
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
            continue;
        if (visited[ny][nx])
            continue;
        int sub = abs(a[ny][nx] - a[y][x]);
        if (sub >= l && sub <= h)
        {
            dfs(ny, nx);
            v.push_back({ny, nx});
            sum += a[ny][nx];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> h;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    while (true)
    {
        flag = 0;
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                {
                    sum = a[i][j];
                    v.clear();

                    dfs(i, j);

                    if (v.size() > 0)
                    {
                        flag = 1;
                        v.push_back({i, j});

                        for (auto it : v)
                        {
                            a[it.first][it.second] = sum / v.size();
                        }
                    }
                }
            }
        }

        if (!flag)
            break;
        cnt++;
    }

    cout << cnt << "\n";
    return 0;
}