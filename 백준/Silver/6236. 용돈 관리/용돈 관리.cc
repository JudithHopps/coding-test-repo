#include <bits/stdc++.h>
using namespace std;
int n, m, a[100004], lo, hi, ret;

bool ch(int mid)
{
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
    lo = max(lo, a[i]);
    hi += a[i];
  }

  while (lo <= hi)
  {
    int mid = (lo + hi) / 2;
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