#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[100001], ret, l, h;

bool ch(int mid)
{
  int sum = 1;
  int temp = mid;
  for (int i = 0; i < n; i++)
  {
    if (temp < a[i])
    {
      temp = mid;
      sum++;
    }
    temp -= a[i];
  }
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
    l = max(l, a[i]);
    h += a[i];
  }

  while (l <= h)
  {
    int mid = (l + h) / 2;
    if (ch(mid))
    {
      h = mid - 1;
      ret = mid;
    }
    else
    {
      l = mid + 1;
    }
  }

  cout << ret << "\n";

  return 0;
}