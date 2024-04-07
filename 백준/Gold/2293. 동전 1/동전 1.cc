#include <bits/stdc++.h>
using namespace std;
int n, k, coin, dp[10004];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  dp[0] = 1;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> coin;

    for (int j = coin; j <= k; j++)
    {
      dp[j] += dp[j - coin];
    }
  }
  cout << dp[k] << "\n";

  return 0;
}