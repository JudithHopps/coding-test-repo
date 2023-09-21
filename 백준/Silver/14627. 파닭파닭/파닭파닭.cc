#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s, c, l[1000004], lo = 1, hi = 1e9, ret, sum;

bool ch(int mid)
{
  int sum = 0;
  for (int i = 0; i < s; i++)
  {
    sum += l[i] / mid;
  }
  return sum >= c;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> s >> c;
  for (int i = 0; i < s; i++)
  {
    cin >> l[i];
    sum += l[i];
  }

  while (lo <= hi)
  {
    ll mid = (lo + hi) / (1LL * 2);
    if (ch(mid))
    {
      ret = mid;
      lo = mid + 1;
    }
    else
    {
      hi = mid - 1;
    }
  }

  cout << sum - ret * c << "\n";

  return 0;
}