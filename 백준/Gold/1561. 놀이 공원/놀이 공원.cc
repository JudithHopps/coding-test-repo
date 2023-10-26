#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, lo, hi = 1e12, ret, temp, a[10004];

bool ch(ll mid)
{
  ll sum = m;
  for (ll i = 0; i < m; i++)
  {
    sum += mid / a[i];
  }
  return n <= sum;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll i = 0; i < m; i++)
  {
    cin >> a[i];
  }
  if (n <= m)
  {
    cout << n << "\n";
    return 0;
  }

  while (lo <= hi)
  {
    ll mid = (lo + hi) / 2;
    if (ch(mid))
    {
      ret = mid;
      hi = mid - 1;
    }
    else
    {
      lo = mid + 1;
    }
  }

  // cout << ret << "\n";

  temp = m;
  for (ll i = 0; i < m; i++)
    temp += ((ret - 1) / a[i]);

  for (ll i = 0; i < m; i++)
  {
    if (ret % a[i] == 0)
      temp++;
    if (temp == n)
    {
      cout << i + 1 << '\n';
      return 0;
    }
  }

  return 0;
}