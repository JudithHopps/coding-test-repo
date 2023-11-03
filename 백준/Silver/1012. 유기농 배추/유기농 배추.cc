#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, y, x, visited[54][54], a[54][54], ret;
const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

bool outside(int y, int x)
{
  if (y < 0 || x < 0 || y >= n || x >= m)
    return true;
  return false;
}
void dfs(int y, int x)
{

  visited[y][x] = 1;

  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (outside(ny, nx) || visited[ny][nx] || a[ny][nx] == 0)
      continue;
    dfs(ny, nx);
  }

  return;
}
int main()
{
  cin >> t;
  while (t--)
  {
    memset(visited, 0, sizeof(visited));
    memset(a, 0, sizeof(a));
    ret = 0;

    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
      scanf("%d %d", &x, &y);
      a[y][x] = 5;
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!visited[i][j] && a[i][j] == 5)
        {
          ret++;
          dfs(i, j);
        }
      }
    }

    cout << ret << "\n";
  }

  return 0;
}