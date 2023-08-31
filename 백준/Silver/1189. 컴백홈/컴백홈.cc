#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, 1, -1};
int r, c, k, visited[10][10];
char a[10][10];

int go(int y, int x)
{
  if (y == 0 && x == c - 1)
  {
    if (k == visited[y][x])
      return 1;
    else
      return 0;
  }

  int ret = 0;
  for (int i = 0; i < 4; i++)
  {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] || a[ny][nx] == 'T')
      continue;
    visited[ny][nx] = visited[y][x] + 1;
    ret += go(ny, nx);
    visited[ny][nx] = 0;
  }

  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> r >> c >> k;

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> a[i][j];
    }
  }

  visited[r - 1][0] = 1;

  cout << go(r - 1, 0) << "\n";

  return 0;
}