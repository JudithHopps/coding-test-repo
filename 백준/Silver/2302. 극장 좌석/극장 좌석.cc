#include <bits/stdc++.h>
using namespace std;
int n, m, cur, vip, dp[41];

void go(int n)
{
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  go(n);
  int ret = 1;

  for (int i = 0; i < m; i++)
  {
    cin >> vip;
    ret *= dp[vip - 1 - cur];
    cur = vip;
  }
  ret *= dp[n - cur];
  cout << ret << "\n";

  return 0;
}