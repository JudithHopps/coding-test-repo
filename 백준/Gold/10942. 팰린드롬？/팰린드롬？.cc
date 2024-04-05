#include <bits/stdc++.h>
using namespace std;
int n, a[2004], from, to, t, dp[2004][2004];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    dp[i][i] = 1;
  }
  for (int i = 0; i < n - 1; i++)
  {
    if (a[i] == a[i + 1])
      dp[i][i + 1] = 1;
  }

  for (int size = 2; size <= n; size++)
  {
    for (int i = 0; i < n - size; i++)
    {
      if (a[i] == a[i + size] && dp[i + 1][i + size - 1])
      {
        dp[i][i + size] = 1;
      }
    }
  }

  cin >> t;
  while (t--)
  {
    cin >> from >> to;
    from--, to--;
    cout << dp[from][to] << "\n";
  }
  return 0;
}