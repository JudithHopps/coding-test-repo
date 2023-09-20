#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ret = 10001, a[100004], l, h;

bool ch(int mid)
{
  int sum = 1;
  int temp = mid;
  for (int i = 0; i < n; i++)
  {
    if (temp < a[i])
    {
      sum++;
      temp = mid;
    }
    temp -= a[i];
  }
  // cout << "mid : " << mid << " sum : " << sum << "\n";
  return sum <= m;
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
    l = max(a[i], l);
  }
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

    // cout << "l  : " << l << "  h :  " << h << "\n";
  }

  cout << ret << "\n";
  return 0;
}