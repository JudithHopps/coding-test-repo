#include <bits/stdc++.h>
using namespace std;
int n;
string pattern, s, ret;
const string ok = "DA", no = "NE";
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> pattern;
  int star = pattern.find('*');
  string left = pattern.substr(0, star);
  string right = pattern.substr(star + 1);
  // cout << right << "\n";
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    ret = ok;
    if (s.size() < pattern.size() - 1)
      ret = no;
    else
    {
      if (left != s.substr(0, star))
        ret = no;
      // cout << s.substr(s.size() - right.size()) << "\n";
      if (right != s.substr(s.size() - right.size()))
        ret = no;
    }
    cout << ret << "\n";
  }
  return 0;
}