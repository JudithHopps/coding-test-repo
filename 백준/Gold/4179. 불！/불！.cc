#include <bits/stdc++.h>
using namespace std;
int r, c, F[1004][1004], J[1004][1004], ret, sx, sy, y, x;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
char a[1004][1004];
const int INF = 987654321;
queue<pair<int, int>> q;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> r >> c;
  fill(&F[0][0], &F[0][0] + 1004 * 1004, INF);

  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> a[i][j];
      if (a[i][j] == 'F')
      {
        F[i][j] = 1;
        q.push({i, j});
      }
      if (a[i][j] == 'J')
      {
        sy = i;
        sx = j;
        J[sy][sx] = 1;
      }
    }
  }

  while (q.size())
  {
    tie(y, x) = q.front();
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= r || nx >= c)
        continue;
      if (F[ny][nx] != INF || a[ny][nx] == '#')
        continue;
      F[ny][nx] = F[y][x] + 1;
      q.push({ny, nx});
    }
  }

  // J
  q.push({sy, sx});
  while (q.size())
  {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    if (y == 0 || x == 0 || y == r - 1 || x == c - 1)
    {
      ret = J[y][x];
      break;
    }

    for (int i = 0; i < 4; i++)
    {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= r || nx >= c)
        continue;
      if (J[ny][nx] || a[ny][nx] == '#')
        continue;
      if (F[ny][nx] <= J[y][x] + 1)
        continue;
      J[ny][nx] = J[y][x] + 1;
      q.push({ny, nx});
    }
  }

  // cout << "J\n";
  // for (int i = 0; i < r; i++)
  // {
  //   for (int j = 0; j < c; j++)
  //   {
  //     cout << J[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  // cout << "\nF\n";
  // for (int i = 0; i < r; i++)
  // {
  //   for (int j = 0; j < c; j++)
  //   {
  //     cout << F[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  if (ret != 0)
    cout << ret << "\n";
  else
    cout << "IMPOSSIBLE\n";
  return 0;
}