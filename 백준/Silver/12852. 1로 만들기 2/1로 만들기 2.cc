#include <bits/stdc++.h>
using namespace std;
int dp[1000004], n;
const int INF = 987654321;

void go(int here)
{
  if (here == 0)
    return;
  cout << here << " ";
  if (here % 3 == 0 && dp[here] == (dp[here / 3] + 1))
    go(here / 3);
  else if (here % 2 == 0 && dp[here] == (dp[here / 2] + 1))
    go(here / 2);
  else if ((here - 1 >= 0) && dp[here] == (dp[here - 1] + 1))
    go(here - 1);
  return;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  fill(dp, dp + 1000004, INF);
  dp[1] = 0;

  for (int i = 2; i <= n; i++)
  {
    if (!(i % 3))
      dp[i] = min(dp[i / 3] + 1, dp[i]);
    if (!(i % 2))
    {
      dp[i] = min(dp[i], dp[i / 2] + 1);
    }
    dp[i] = min(dp[i], dp[i - 1] + 1);
  }

  cout << dp[n] << "\n";
  go(n);

  return 0;
}