#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, attack, t[130004], a[130004], h[130004], ret;

bool ch(ll mid)
{
  ll mxH = mid;
  ll at = attack;
  for (int i = 0; i < n; i++)
  {
    if (t[i] == 1)
    {
      ll cnt = h[i] / at + (h[i] % at ? 1 : 0);
      mid -= (cnt - 1) * a[i];
    }
    if (t[i] == 2)
    {
      at += a[i];
      mid = min(mxH, mid + h[i]);
    }
    if (mid <= 0)
      return false;
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

  ll lo = 1, hi = 1e18 + 4;
  while (lo <= hi)
  {
    ll mid = (lo + hi) / 2;
    // cout << "lo : " << lo << "  hi : " << hi << "\n";
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