#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000000;
int n;
long long dp[104][10], ret;

long long go(int idx, int now)
{
  if (idx == n)
    return 1;
  long long &ret = dp[idx][now];
  if (ret)
    return ret;

  if (now != 9)
  {
    ret += (go(idx + 1, now + 1) % MOD);
  }

  if (now != 0)
  {
    ret += (go(idx + 1, now - 1) % MOD);
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 1; i <= 9; i++)
  {
    ret = (ret + go(1, i)) % MOD;
  }
  cout << ret << "\n";
  return 0;
}