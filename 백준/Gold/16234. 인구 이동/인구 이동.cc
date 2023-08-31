#include <bits/stdc++.h>
using namespace std;
int n, l, r, a[54][54], ret, visited[54][54], sum, cnt;
const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};
bool flag;
vector<pair<int, int>> v;
void dfs(int y, int x)
{
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx])
      continue;
    if (abs(a[y][x] - a[ny][nx]) >= l && abs(a[y][x] - a[ny][nx]) <= r)
    {
      visited[ny][nx] = 1;
      v.push_back({ny, nx});
      sum += a[ny][nx];
      dfs(ny, nx);
    }
  }

  return;
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
    flag = false;
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

          dfs(i, j);

          if (v.size() > 1)
          {
            flag = true;
            for (auto it : v)
            {
              a[it.first][it.second] = sum / v.size();
            }
          }
        }
      }
    }

    if (!flag)
    {
      break;
    }
    ret++;
  }

  cout << ret << "\n";
  return 0;
}