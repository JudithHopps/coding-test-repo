#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r, l, ret;
ll n, m, a[100004];

bool check(ll mid)
{
  ll cnt = 0;

  for (int i = 0; i < n; i++)
  {
    cnt += mid / a[i];
  }
  return cnt >= m;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);

  // for (int i = 0; i < n; i++)
  //   cout << a[i] << " ";
  // cout << "\n";
  l = 1LL;
  r = a[0] * m;
  ret = r;

  while (l <= r)
  {
    ll mid = (l + r) / 2;

    if (check(mid))
    {
      ret = mid;
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }

  cout << ret << "\n";
  return 0;
}