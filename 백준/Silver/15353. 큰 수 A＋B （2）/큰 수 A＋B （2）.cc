#include <bits/stdc++.h>
using namespace std;
int cur;
string a, b, ret;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b;
  int aLength = a.length() - 1;
  int bLength = b.length() - 1;
  int mx = max(aLength, bLength);
  // cout << "\n"
  //      << a[aLength] << "\n";

  for (int i = 0; i <= mx; i++)
  {
    cur = cur / 10;
    // cout << cur << "\n";
    if (aLength >= 0)
    {
      cur += a[aLength] - '0';
      // cout << cur << "\n";
      aLength--;
    }
    if (bLength >= 0)
    {
      cur += b[bLength] - '0';
      // cout << cur << "\n";
      bLength--;
    }
    ret += to_string(cur % 10);
  }
  if ((cur / 10) > 0)
    ret += to_string(cur / 10);

  reverse(ret.begin(), ret.end());
  cout << ret << "\n";

  return 0;
}