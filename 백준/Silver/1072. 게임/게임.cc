#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, y, z, ret = -1, lo = 1, hi = 1e9;

bool ch(ll mid)
{
  ll curZ = (y + mid) * 100 / (x + mid);
  return curZ > z;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> x >> y;
  z = (y*100) / x ;

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