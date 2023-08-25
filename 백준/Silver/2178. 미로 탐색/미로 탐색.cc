#include <bits/stdc++.h>
using namespace std;
int n, m, a[104][104], visited[104][104];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

string str;
// bfs - 100 * 100

void bfs(int y, int x)
{
  visited[y][x] = 1;
  queue<pair<int, int>> q;
  q.push({y, x});

  while (q.size())
  {
    tie(y, x) = q.front();
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || a[ny][nx] == 0)
        continue;
      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
  }
  return;
}
int main()
{
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("%1d", &a[i][j]);
    }
  }

  bfs(0, 0);

  printf("%d ", visited[n - 1][m - 1]);

  return 0;
}