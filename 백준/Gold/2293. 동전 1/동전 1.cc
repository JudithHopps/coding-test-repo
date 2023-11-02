#include <bits/stdc++.h>
using namespace std;
// 경우의 수 : 더하기!!
int dp[10001], temp, n, k;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  dp[0] = 1;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    for (int j = temp; j <= k; j++)
    {
      dp[j] += dp[j - temp];
    }
  }

  cout << dp[k] << "\n";
  return 0;
}