#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, a[100004], ret = INF, lo = 1, hi, mx;

bool ch(int mid)
{
  if (mx > mid)
    return false;
  int cnt = 0, cur = 0;
  for (int i = 0; i < n; i++)
  {
    if (mid >= cur + a[i])
    {
      cur += a[i];
    }
    else
    {
      cnt++;
      cur = a[i];
    }
  }
  if (cur > 0)
    cnt++;
  return cnt <= m;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    hi += a[i];
    mx = max(mx, a[i]);
  }

  while (lo <= hi)
  {
    int mid = (lo + hi) / 2;

    if (ch(mid))
    {
      ret = mid;
      hi = mid - 1;
    }
    else
      lo = mid + 1;
  }

  cout << ret << "\n";

  return 0;
}