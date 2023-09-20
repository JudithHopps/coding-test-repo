#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, attack, t[123460], a[123460], h[123460], ret, lo = 1, hi = 1e18 + 4;

bool ch(ll mid)
{
  ll maxH = mid;
  ll at = attack;

  for (int i = 0; i < n; i++)
  {
    if (t[i] == 1)
    {
      ll cnt = h[i] / at + (h[i] % at ? 1 : 0) - 1;
      mid -= cnt * a[i];
      if (mid <= 0)
        return false;
    }
    else
    {
      at += a[i];
      mid = min(maxH, mid + h[i]);
    }
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> attack;

  for (int i = 0; i < n; i++)
  {
    cin >> t[i] >> a[i] >> h[i];
  }

  while (lo <= hi)
  {
    ll mid = (lo + hi) / 2;
    if (ch(mid))
    {
      hi = mid - 1;
      ret = mid;
    }
    else
    {
      lo = mid + 1;
    }
  }

  cout << ret << "\n";
  return 0;
}