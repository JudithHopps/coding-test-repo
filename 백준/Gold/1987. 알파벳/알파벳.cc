#include <bits/stdc++.h>
using namespace std;
int r, c, ret, visited[30];
char a[21][21];
const int dy[] = {0, 0, -1, 1}, dx[] = {1, -1, 0, 0};

void dfs(int y, int x, int cnt)
{
  ret = max(ret, cnt);

  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= r || nx >= c)
      continue;
    int next = a[ny][nx] - 'A';
    if (visited[next] == 0)
    {
      visited[next]++;
      dfs(ny, nx, cnt + 1);
      visited[next]--;
    }
  }
  return;
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
    }
  }

  visited[a[0][0] - 'A']++;
  dfs(0, 0, 1);

  cout << ret << "\n";
  return 0;
}