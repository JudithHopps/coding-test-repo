#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[94], n;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  dp[0] = 0;
  dp[1] = 1;
  cin >> n;
  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  cout << dp[n] << "\n";

  return 0;
}