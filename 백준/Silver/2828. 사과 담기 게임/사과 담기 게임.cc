#include <bits/stdc++.h>
using namespace std;
int n, m, j, l = 1, r, temp, ret;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> j;
  for (int i = 0; i < j; i++)
  {
    r = l + m - 1;
    cin >> temp;
    if (l <= temp && temp <= r)
      continue;
    else if (r < temp)
    {
      ret += temp - r;
      l = temp - m + 1;
    }
    if (temp < l)
    {
      ret += (l - temp);
      l = temp;
      // cout << "T\n";
    }
    // cout << "i :" << i << " " << ret << "\n";
  }
  cout << ret << "\n";
  return 0;
}