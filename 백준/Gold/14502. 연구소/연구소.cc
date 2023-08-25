#include <bits/stdc++.h>
using namespace std;
int n, m, ret, a[10][10], visited[10][10];
vector<pair<int, int>> virus, zero;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void dfs(int y, int x)
{
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || a[ny][nx] != 0)
      continue;
    dfs(ny, nx);
  }
}
int solve()
{
  int sum = 0;
  fill(&visited[0][0], &visited[0][0] + 100, 0);
  for (auto it : virus)
  {
    dfs(it.first, it.second);
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (a[i][j] == 0 && !visited[i][j])
        sum++;
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

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
      if (a[i][j] == 2)
        virus.push_back({i, j});
      if (a[i][j] == 0)
        zero.push_back({i, j});
    }
  }

  for (int i = 0; i < zero.size(); i++)
  {
    for (int j = 0; j < i; j++)
    {
      for (int k = 0; k < j; k++)
      {
        a[zero[i].first][zero[i].second] = 1;
        a[zero[j].first][zero[j].second] = 1;
        a[zero[k].first][zero[k].second] = 1;

        ret = max(ret, solve());

        a[zero[i].first][zero[i].second] = 0;
        a[zero[j].first][zero[j].second] = 0;
        a[zero[k].first][zero[k].second] = 0;
      }
    }
  }
  cout << ret << "\n";
  return 0;
}