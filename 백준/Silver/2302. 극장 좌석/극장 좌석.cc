#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, dp[41], cnt[41], temp;

int go(int pos)
{
  if (pos >= n)
    return 1;
  if (cnt[pos])
    return go(pos + 1);
  if (dp[pos] != -1)
    return dp[pos];

  int &ret = dp[pos];
  ret = 0;

  if (!cnt[pos + 1])
    ret += (go(pos + 2) + go(pos + 1));
  else
    ret += go(pos + 1);

  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> temp;
    cnt[temp] = 1;
  }

  memset(dp, -1, sizeof(dp));
  cout << go(1) << "\n";

  return 0;
}