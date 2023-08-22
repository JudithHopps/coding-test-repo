#include <bits/stdc++.h>
using namespace std;
const int maxN = 104;
int n, m, a[maxN][maxN], visited[maxN][maxN];
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

void bfs(int sy, int sx)
{
  visited[sy][sx] = 1;
  queue<pair<int, int>> q;
  q.push({sy, sx});

  while (q.size())
  {
    int y, x;
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= n || nx >= m)
        continue;
      if (a[ny][nx] && !visited[ny][nx])
      {
        q.push({ny, nx});
        visited[ny][nx] = visited[y][x] + 1;
      }
    }
  }
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

  printf("%d\n", visited[n - 1][m - 1]);

  return 0;
}