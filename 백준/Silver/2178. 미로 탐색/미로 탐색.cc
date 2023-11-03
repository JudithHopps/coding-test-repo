#include <bits/stdc++.h>
using namespace std;
int n, m, a[104][104], visited[104][104];
const int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

void go(int y, int x)
{
  queue<pair<int, int>> q;
  visited[y][x] = 1;
  q.push({y, x});

  while (q.size())
  {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 0)
        continue;

      if (visited[ny][nx])
        continue;

      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
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

  go(0, 0);

  cout << visited[n - 1][m - 1] << "\n";

  return 0;
}