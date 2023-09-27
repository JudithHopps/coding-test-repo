#include <bits/stdc++.h>
using namespace std;
int n, che[24], join[24], cur = 100, dp[104];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> che[i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> join[i];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 100; j > che[i]; j--)
    {
      dp[j] = max(dp[j], dp[j - che[i]] + join[i]);
    }
  }

  cout << dp[100] << "\n";
  return 0;
}