#include <bits/stdc++.h>
using namespace std;
// 비의 양에 따른 모든 경우를
int ret = 1, n, a[104][104], visited[104][104], mx;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

void dfs(int y, int x, int h)
{
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= n || nx >= n)
      continue;
    if (visited[ny][nx] || a[ny][nx] <= h)
      continue;

    dfs(ny, nx, h);
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
      if (a[i][j] > mx)
      {
        mx = a[i][j];
      }
    }
  }

  for (int h = 1; h < mx; h++)
  {
    memset(visited, 0, sizeof(visited));
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (!visited[i][j] && a[i][j] > h)
        {
          dfs(i, j, h);
          cnt++;
        }
      }
    }

    ret = max(ret, cnt);
  }

  cout << ret << "\n";
  return 0;
}