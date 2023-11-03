#include <bits/stdc++.h>
using namespace std;
int n, money, f, s, dp[10004];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true)
  {
    scanf("%d %d.%d", &n, &f, &s);
    if (n == 0 && f == 0 && s == 0)
      break;

    money = f * 100 + s;
    memset(dp, 0, sizeof(dp));

    vector<int> c(n + 4), m(10004);
    for (int i = 0; i < n; i++)
    {
      scanf("%d %d.%d", &c[i], &f, &s);
      m[i] = f * 100 + s;

      for (int j = m[i]; j <= money; j++)
      {
        dp[j] = max(dp[j], dp[j - m[i]] + c[i]);
      }
    }

    cout << dp[money] << "\n";
  }

  return 0;
}