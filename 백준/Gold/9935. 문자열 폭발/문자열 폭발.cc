#include <bits/stdc++.h>
using namespace std;
string str, del, ret;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> str >> del;

  for (int i = 0; i < str.length(); i++)
  {
    ret += str[i];
    if (ret.size() >= del.size() && ret.substr(ret.size() - del.size(), del.size()) == del)
    {
      ret.erase(ret.end() - del.size(), ret.end());
    }
  }

  if (!ret.size())
    cout << "FRULA\n";
  else
    cout << ret << "\n";

  return 0;
}