#include <bits/stdc++.h>
using namespace std;
int n, che[24], joy[24], dp[104];

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
    cin >> joy[i];
  }

  for (int i = 0; i < n; i++)
  {

    for (int c = 100; c > che[i]; c--)
    {

      dp[c] = max(dp[c], dp[c - che[i]] + joy[i]);
    }
  }

  cout << dp[100] << "\n";
  return 0;
}