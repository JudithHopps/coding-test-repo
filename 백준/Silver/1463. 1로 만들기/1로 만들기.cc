#include <bits/stdc++.h>
using namespace std;
int n, dp[1000004];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  const int INF = 987654321;
  fill(dp, dp + 1000004, INF);
  dp[1] = 0;

  for (int i = 2; i <= n; i++)
  {
    if (i >= 3 && i % 3 == 0)
    {
      dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    if (i >= 2 && i % 2 == 0)
    {
      dp[i] = min(dp[i], dp[i / 2] + 1);
    }
    dp[i] = min(dp[i], dp[i - 1] + 1);
  }

  cout << dp[n] << "\n";
  return 0;
}