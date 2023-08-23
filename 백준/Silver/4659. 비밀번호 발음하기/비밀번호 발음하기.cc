#include <bits/stdc++.h>
using namespace std;
string str;
string ok = "> is acceptable.";
string no = "> is not acceptable.";
vector<char> a = {'a', 'e', 'i', 'o', 'u'};
string test(string s)
{
  int cntA = 0, cntB = 0, sumA = 0;
  char pre;
  for (char c : s)
  {
    if (find(a.begin(), a.end(), c) != a.end())
    {
      cntA++;
      sumA++;
      if (cntA == 3)
      {
        return no;
      }
      cntB = 0;
    }

    else
    {
      cntB++;
      if (cntB == 3)
      {
        return no;
      }
      cntA = 0;
    }
    if (pre == c)
    {
      if (pre == 'e' || pre == 'o')
        continue;
      return no;
    }
    // cout << "    p :" << pre << "   c : " << c << "  sumA : " << sumA << "\n";
    pre = c;
  }

  return sumA >= 1 ? ok : no;
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
    cout << "<" << str << test(str) << "\n";
  }

  return 0;
}