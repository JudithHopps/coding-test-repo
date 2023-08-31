#include <bits/stdc++.h>
using namespace std;
int r, c, visited[54][54], ret;
char a[54][54];
vector<pair<int, int>> land;
const int dy[] = {0, 0, -1, 1}, dx[] = {1, -1, 0, 0};

int bfs(int y, int x)
{
  visited[y][x] = 1;
  queue<pair<int, int>> q;
  q.push({y, x});

  int dist = 0;

  while (q.size())
  {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] || a[ny][nx] == 'W')
        continue;
      visited[ny][nx] = visited[y][x] + 1;
      dist = max(dist, visited[ny][nx]);
      q.push({ny, nx});
    }
  }
  // cout << dist << "\n";
  return dist;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> r >> c;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> a[i][j];
      if (a[i][j] == 'L')
      {
        land.push_back({i, j});
      }
    }
  }

  for (auto it : land)
  {
    memset(visited, 0, sizeof(visited));

    ret = max(ret, bfs(it.first, it.second));
  }
  cout << ret - 1 << "\n";

  return 0;
}