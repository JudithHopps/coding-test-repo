#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ret, n, k, a[104], dp[10004];
const int INF = 987654321;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  dp[0] = 1;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (a[i] >= 10001)
      continue;
    for (int j = a[i]; j <= k; j++)
    {
      dp[j] += dp[j - a[i]];
    }
  }
  cout << dp[k] << "\n";

  return 0;
}