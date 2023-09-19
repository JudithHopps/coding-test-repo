#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ret = 1e18, a[300004];

bool ch(int mid)
{
  int sum = 0;
  for (int i = 0; i < m; i++)
  {
    sum += a[i] / mid;
    sum += (a[i] % mid ? 1 : 0);
  }
  return n >= sum;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  ll l = 1, h, mid;
  for (int i = 0; i < m; i++)
  {
    cin >> a[i];
    h = max(h, a[i]);
  }

  while (l <= h)
  {
    mid = (l + h) / 2;
    if (ch(mid))
    {
      ret = min(ret, mid);
      h = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }

  cout << ret << "\n";

  return 0;
}