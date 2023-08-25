#include <bits/stdc++.h>
using namespace std;
string str;
string ok = "> is acceptable.", no = "> is not acceptable.";
char pre;
bool isVower(char idx)
{
  return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

string ch(string s)
{
  int v = 0, cnt = 0, ret = 0;
  {

    for (char c : s)
    {
      if (isVower(c))
      {

        v++;
        ret++;
        cnt = 0;
        if (v == 3)
          return no;
      }
      else
      {
        v = 0;
        cnt++;
        if (cnt == 3)
          return no;
      }

      if (pre == c && (c != 'e' && c != 'o'))
      {
        return no;
      }
      pre = c;
    }
  }
  if (ret)
    return ok;
  return no;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true)
  {
    cin >> str;
    if (str == "end")
      break;
    pre = '-';
    cout << "<" << str << ch(str) << "\n";
  }
  return 0;
}