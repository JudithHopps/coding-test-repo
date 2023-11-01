#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, dp[16][1 << 16], w[16][16];

int go(int here, int visited)
{
  if (visited == (1 << n) - 1)
  {
    return w[here][0] ? w[here][0] : INF;
  }
  int &ret = dp[here][visited];
  if (ret != -1)
    return ret;
  ret = INF;

  for (int i = 1; i < n; i++)
  {
    if (w[here][i] == 0 || visited & 1 << i)
      continue;
    ret = min(ret, go(i, visited | 1 << i) + w[here][i]);
  }
  return ret;
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
      cin >> w[i][j];
    }
  }

  memset(dp, -1, sizeof(dp));

  cout << go(0, 1) << "\n";

  return 0;
}