#include <bits/stdc++.h>
using namespace std;
int m, n, k, a[104][104], sy, sx, ex, ey, temp;
int visited[104][104];
vector<int> ret;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};

void dfs(int y, int x)
{
  temp++;
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= m || nx >= n || a[ny][nx] || visited[ny][nx])
      continue;
    dfs(ny, nx);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m >> n >> k;
  for (int i = 0; i < k; i++)
  {
    cin >> sx >> sy >> ex >> ey;
    for (int x = sx; x < ex; x++)
    {
      for (int y = sy; y < ey; y++)
      {
        a[y][x] = 1;
      }
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      // cout << a[i][j] << " ";
      temp = 0;
      if (visited[i][j] == 0 && a[i][j] == 0)
      {
        dfs(i, j);

        ret.push_back(temp);
      }
    }
    // cout << "\n";
  }

  sort(ret.begin(), ret.end());
  cout << ret.size() << "\n";
  for (int i : ret)
  {
    if (i)
      cout << i << " ";
  }
  return 0;
}