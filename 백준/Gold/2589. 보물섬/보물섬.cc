#include <bits/stdc++.h>
using namespace std;
int ret, r, w, visited[54][54];
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};
char a[54][54];

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
      if (ny < 0 || nx < 0 || ny >= r || nx >= w || visited[ny][nx] || a[ny][nx] == 'W')
        continue;
      q.push({ny, nx});
      visited[ny][nx] = visited[y][x] + 1;

      ret = max(ret, visited[ny][nx]);
    }
  }
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> r >> w;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if (a[i][j] == 'L')
      {
        memset(visited, 0, sizeof(visited));
        bfs(i, j);
      }
    }
  }

  cout << ret - 1 << "\n";

  return 0;
}