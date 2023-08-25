#include <bits/stdc++.h>
using namespace std;
int n, m, j, l = 1, r, cur, ret;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> j;

  for (int i = 0; i < j; i++)
  {
    r = l + m - 1;
    cin >> cur;
    if (r < cur)
    {
      ret += cur - r;
      l = cur - m + 1;
    }
    if (cur < l)
    {
      ret += l - cur;
      l = cur;
    }
  }
  cout << ret << "\n";
  return 0;
}