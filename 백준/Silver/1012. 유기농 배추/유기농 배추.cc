#include <bits/stdc++.h>
using namespace std;
int t, m, n, k, a[54][54], visited[54][54];
;
int y, x, ny, nx, ret;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

void dfs(int y, int x)
{
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny > m || nx > n)
      continue;
    if (a[ny][nx] && !visited[ny][nx])
    {
      dfs(ny, nx);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  while (t--)
  {
    // 초기화 방법
    fill(&a[0][0], &a[0][0] + 54 * 54, 0);
    fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
    ret = 0;
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
      cin >> y >> x;
      a[y][x] = 1;
    }

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (visited[i][j] == 0 && a[i][j])
        {
          ret++;
          dfs(i, j);
        }
      }
    }
    cout << ret << "\n";
  }
  return 0;
}