#include <bits/stdc++.h>
using namespace std;
int n;
string str, s, pre, suf;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> str;

  int idx = str.find('*');
  pre = str.substr(0, idx);
  suf = str.substr(idx + 1);

  for (int i = 0; i < n; i++)
  {
    cin >> s;

    if (s.size() < pre.size() + suf.size())
    {
      cout << "NE\n";
    }
    else
    {
      if (pre == s.substr(0, idx) && suf == s.substr(s.size() - suf.size()))
      {
        cout << "DA\n";
      }
      else
      {
        cout << "NE\n";
      }
    }
  }
  return 0;
}