#include <bits/stdc++.h>
using namespace std;
int n, m1, m2, have, a, c1, c2, cost, dp[100004];
int main()
{
  while (true)
  {
    scanf("%d %d.%d", &n, &m1, &m2);
    if (n == 0)
      break;
    memset(dp, 0, sizeof(dp));
    have = m1 * 100 + m2;
    for (int i = 0; i < n; i++)
    {
      scanf("%d %d.%d", &a, &c1, &c2);
      cost = c1 * 100 + c2;
      for (int j = cost; j <= have; j++)
      {
        dp[j] = max(dp[j], dp[j - cost] + a);
      }
    }
    printf("%d\n", dp[have]);
  }

  return 0;
}