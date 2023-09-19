#include <bits/stdc++.h>
using namespace std;
int n, m, mx, a[100004], ret = 100001, l, h;

bool ch(int mid)
{
  if (mx > mid)
    return false;
  int temp = mid, cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (temp - a[i] < 0)
    {
      temp = mid;
      cnt++;
    }
    temp -= a[i];
  }
  if (temp != mid)
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
    h += a[i];
    mx = max(mx, a[i]);
  }

  // cout << "l  : " << l << "  h  : " << h << "\n";

  while (l <= h)
  {
    int mid = (l + h) / 2;
    if (ch(mid))
    {
      ret = mid;
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