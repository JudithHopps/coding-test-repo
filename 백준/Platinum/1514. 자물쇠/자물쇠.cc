#include <bits/stdc++.h>
using namespace std;
int n, a[104], b[104], dp[104][10][10][10][2];
const int INF = 987654321;
int cal(int m)
{
  return (m < 0) ? m + 10 : m % 10;
}

int go(int pos, int x, int y, int z, int flag)
{
  if (pos == n)
    return 0;
  int &ret = dp[pos][x][y][z][flag];
  if (ret != -1)
    return ret;
  if (cal(x + a[pos]) == b[pos])
    return ret = min(go(pos + 1, y, z, 0, 0), go(pos + 1, y, z, 0, 1));

  int f = flag == 1 ? 1 : -1;
  ret = INF;
  for (int i = 1; i <= 3; i++)
  {
    ret = min(ret, go(pos, cal(x + i * f), y, z, flag) + 1);
    ret = min(ret, go(pos, cal(x + i * f), cal(y + i * f), z, flag) + 1);
    ret = min(ret, go(pos, cal(x + i * f), cal(y + i * f), cal(z + i * f), flag) + 1);
  }
  return ret;
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%1d", &a[i]);
  }
  for (int i = 0; i < n; i++)
  {
    scanf("%1d", &b[i]);
  }
  memset(dp, -1, sizeof(dp));
  cout << min(go(0, 0, 0, 0, 0), go(0, 0, 0, 0, 1)) << "\n";

  return 0;
}