#include <bits/stdc++.h>
using namespace std;
int n, a[104][104], ret = 1, m, visited[104][104], ny, nx;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void dfs(int sy, int sx, int k)
{
  visited[sy][sx] = 1;
  for (int i = 0; i < 4; i++)
  {
    ny = sy + dy[i];
    nx = sx + dx[i];
    if (ny < 0 || nx < 0 || ny >= n || nx >= n)
      continue;
    if (a[ny][nx] > k && !visited[ny][nx])
    {
      dfs(ny, nx, k);
    }
  }
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
      m = max(m, a[i][j]);
    }
  }

  for (int k = 1; k <= 100; k++)
  {
    int cnt = 0;
    fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (!visited[i][j] && a[i][j] > k)
        {
          dfs(i, j, k);
          cnt++;
        }
      }
    }

    ret = max(cnt, ret);
  }
  cout << ret << "\n";
  return 0;
}