#include <bits/stdc++.h>
using namespace std;
int n;
string str, ret;
vector<string> v;

bool cmp(string a, string b)
{
  if (a.size() == b.size())
    return a < b;
  else
    return a.size() < b.size();
}

void go()
{
  while (true)
  {
    if (ret.size() && ret.front() == '0')
      ret.erase(ret.begin());
    else
      break;
  }

  if (ret.size() == 0)
    ret = "0";

  v.push_back(ret);
  ret = "";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  while (n--)
  {
    cin >> str;
    ret = "";
    for (char c : str)
    {
      if (c < 65)
        ret += c;
      else if (ret.size())
        go();
    }
    if (ret.size())
      go();
  }

  sort(v.begin(), v.end(), cmp);

  for (string s : v)
  {
    cout << s << "\n";
  }

  return 0;
}