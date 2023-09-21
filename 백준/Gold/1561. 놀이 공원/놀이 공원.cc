#include <bits/stdc++.h>
using namespace std;
#define maxN 60000000004
#define maxM 10004
typedef long long ll;
ll n, m, a[maxM], lo, hi = maxN, ret, mid, temp;

bool ch(ll mid)
{
  temp = m;
  for (ll i = 0; i < m; i++)
    temp += mid / a[i];
  return temp >= n;
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
    mid = (lo + hi) / (1LL * 2);
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
  temp = m;
  for (ll i = 0; i < m; i++)
  {
    temp += (ret - 1) / a[i];
  }
  for (ll i = 0; i < m; i++)
  {
    if (ret % a[i] == 0)
      temp++;
    if (temp == n)
    {
      cout << i + 1 << "\n";
      return 0;
    }
  }
  return 0;
}