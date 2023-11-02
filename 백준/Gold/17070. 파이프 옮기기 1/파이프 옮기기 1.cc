#include <bits/stdc++.h>
using namespace std;
int n, a[20][20], dp[20][20][4], ret;

bool check(int y, int x, int dir)
{
  if (dir == 1 || dir == 2)
  {
    if (!a[y][x])
      return true;
  }
  else
  {
    if (a[y][x] == 0 && a[y - 1][x] == 0 && a[y][x - 1] == 0)
    {
      return true;
    }
  }
  return false;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }

  dp[0][1][1] = 1;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (check(i, j + 1, 1))
      {
        dp[i][j + 1][1] += dp[i][j][1];
        dp[i][j + 1][1] += dp[i][j][3];
      }

      if (check(i + 1, j, 2))
      {
        dp[i + 1][j][2] += dp[i][j][2];
        dp[i + 1][j][2] += dp[i][j][3];
      }

      if (check(i + 1, j + 1, 3))
      {
        dp[i + 1][j + 1][3] += dp[i][j][1] + dp[i][j][2] + dp[i][j][3];
      }
    }
  }

  ret = dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2] + dp[n - 1][n - 1][3];
  cout << ret << "\n";

  return 0;
}