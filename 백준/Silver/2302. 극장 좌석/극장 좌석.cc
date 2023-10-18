#include <bits/stdc++.h>
using namespace std;
int n, m, vip, cur;
long long dp[41];
vector<int> v;

void countSeatingArrangements(int n)
{
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return;
}

int main()
{

  cin >> n >> m;
  countSeatingArrangements(n);
  int ret = 1;

  for (int i = 0; i < m; i++)
  {
    cin >> vip;
    ret *= dp[vip - cur - 1];
    cur = vip;
  }
  ret *= dp[n - cur];

  cout << ret << "\n";
  return 0;
}
