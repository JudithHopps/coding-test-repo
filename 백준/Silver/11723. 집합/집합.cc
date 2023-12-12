#include <bits/stdc++.h>
using namespace std;
int m, cur, a;
string s;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m;
  while (m--)
  {
    cin >> s;
    if (s == "add")
    {
      cin >> a;
      cur |= (1 << a);
    }
    if (s == "check")
    {
      cin >> a;
      cout << ((cur & (1 << a)) ? 1 : 0) << "\n";
    }
    if (s == "toggle")
    {
      cin >> a;
      cur ^= (1 << a);
    }
    if (s == "remove")
    {
      cin >> a;
      cur &= ~(1 << a);
    }
    if (s == "all")
    {
      cur = (1 << 21) - 1;
    }
    if (s == "empty")
    {
      cur = 0;
    }
  }

  return 0;
}