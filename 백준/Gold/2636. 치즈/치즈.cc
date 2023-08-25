#include <bits/stdc++.h>
using namespace std;
int n, m, tim, siz, a[104][104], visited[104][104];
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
vector<pair<int, int>> v;

void dfs(int y, int x)
{
  visited[y][x] = 1;
  if (a[y][x] == 1)
  {
    v.push_back({y, x});
    return;
  }

  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= n || nx >= m)
      continue;
    if (!visited[ny][nx])
    {
      dfs(ny, nx);
    }
  }

  return;
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
    }
  }

  while (true)
  {
    fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
    v.clear();
    siz = 0;

    dfs(0, 0);
    for (auto it : v)
    {
      a[it.first][it.second] = 0;
      siz++;
    }
    tim++;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (a[i][j] == 1)
          flag = true;
      }
    }
    if (!flag)
      break;
  }

  cout << tim << "\n"
       << siz << "\n";
  return 0;
}