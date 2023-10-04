#include <bits/stdc++.h>
using namespace std;
int n, m, c, a[14], dp[14][1 << 14][24];

int go(int bag, int yam, int capacity)
{
  if (bag == m)
    return 0;
  int &ret = dp[bag][yam][capacity];
  if (ret)
    return ret;

  ret = max(ret, go(bag + 1, yam, c));

  for (int i = 0; i < n; i++)
  {
    bool had = yam & (1 << i);
    bool can = capacity - a[i] >= 0;
    if (!had && can)
    {
      ret = max(ret, go(bag, yam | (1 << i), capacity - a[i]) + 1);
    }
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> c;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  cout << go(0, 0, c) << "\n";

  return 0;
}