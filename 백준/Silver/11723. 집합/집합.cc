#include <bits/stdc++.h>
using namespace std;
int m, num, cur;
string str;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> str;
    if (str == "all")
    {
      num = (1 << 21) - 1;
    }
    else if (str == "empty")
    {
      num = 0;
    }
    else
    {
      cin >> cur;

      if (str == "add")
      {
        num |= (1 << cur);
      }
      else if (str == "check")
      {
        cout << (num & (1 << cur) ? 1 : 0) << "\n";
      }
      else if (str == "remove")
      {
        num &= ~(1 << cur);
      }
      else if (str == "toggle")
      {
        num ^= (1 << cur);
      }
    }
  }

  return 0;
}