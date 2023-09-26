#include <bits/stdc++.h>
using namespace std;
const int mod = 1000007;
int n, m, c, y, x, dp[54][54][54][54], a[54][54];

int go(int y, int x, int cnt, int pre)
{
  if (y > n || x > m)
  {
    return 0;
  }
  if (y == n && x == m)
  {
    if (cnt == 0 && a[n][m] == 0)
    {
      return 1;
    }
    if (cnt == 1 && a[n][m] > pre)
    {
      return 1;
    }
    return 0;
  }

  int &ret = dp[y][x][cnt][pre];
  if (~ret)
    return ret;
  ret = 0;

  if (a[y][x] == 0)
  {
    ret = (go(y + 1, x, cnt, pre) + go(y, x + 1, cnt, pre)) % mod;
  }
  else if (a[y][x] > pre)
  {
    ret = (go(y + 1, x, cnt - 1, a[y][x]) + go(y, x + 1, cnt - 1, a[y][x])) % mod;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> c;
  for (int i = 1; i <= c; i++)
  {
    cin >> y >> x;
    a[y][x] = i;
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i <= c; i++)
  {
    cout << go(1, 1, i, 0) << " ";
  }

  return 0;
}