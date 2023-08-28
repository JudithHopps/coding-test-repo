#include <bits/stdc++.h>
using namespace std;
int n, r, l, a[54][54], visited[54][54], cnt, sum;
vector<pair<int, int>> v;
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

void dfs(int y, int x, vector<pair<int, int>> &v)
{
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx])
      continue;
    if (abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r)
    {
      v.push_back({ny, nx});
      sum += a[ny][nx];
      dfs(ny, nx, v);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> l >> r;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }

  while (true)
  {
    bool flag = 0;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (!visited[i][j])
        {
          sum = a[i][j];
          v.clear();
          v.push_back({i, j});

          dfs(i, j, v);

          if (v.size() > 1)
          {
            flag = 1;
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