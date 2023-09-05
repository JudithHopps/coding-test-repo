#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, mx, big, a[54][54], visited[54][54], area[2504];
const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};
int dfs(int y, int x, int cnt)
{
  if (visited[y][x])
    return 0;
  visited[y][x] = cnt;
  int sum = 1;
  for (int i = 0; i < 4; i++)
  {
    if (!(a[y][x] & (1 << i)))
    {
      int ny = y + dy[i];
      int nx = x + dx[i];
      sum += dfs(ny, nx, cnt);
    }
  }
  return sum;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (!visited[i][j])
      {

        cnt++;
        area[cnt] = dfs(i, j, cnt);
        mx = max(mx, area[cnt]);
      }
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i + 1 < m)
      {
        int a = visited[i][j];
        int b = visited[i + 1][j];
        if (a != b)
        {
          big = max(big, area[a] + area[b]);
        }
      }
      if (j + 1 < n)
      {
        int a = visited[i][j];
        int b = visited[i][j + 1];
        if (a != b)
        {
          big = max(big, area[a] + area[b]);
        }
      }
    }
  }

  cout << cnt << "\n"
       << mx << "\n"
       << big << "\n";
  return 0;
}