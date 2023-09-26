#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, k, ret = -1, temp, dp[10004];
vector<int> coin;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  fill(dp, dp + 10004, INF);
  dp[0] = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    for (int j = temp; j <= k; j++)
    {
      dp[j] = min(dp[j], dp[j - temp] + 1);
    }
  }

   cout << (dp[k] == INF ? -1 : dp[k]) << "\n";

  return 0;
}