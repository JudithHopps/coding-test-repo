#include <bits/stdc++.h>
using namespace std;
int n, win, A, B, asum, bsum;
string hhmm, pre;

string print(int sum)
{
  string hh = "00" + to_string(sum / 60);
  string mm = "00" + to_string(sum % 60);
  return hh.substr(hh.size() - 2, 2) + ":" + mm.substr(mm.size() - 2, 2);
}
int stringToInt(string s)
{
  return atoi(s.c_str());
}
int go(string a, string b)
{
  return -(stringToInt(a.substr(0, 2)) * 60 + stringToInt(a.substr(a.size() - 2, 2))) + (stringToInt(b.substr(0, 2)) * 60 + stringToInt(b.substr(b.size() - 2, 2)));
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> win >> hhmm;
    if (i > 0)
    {
      // cout << "pre : " << pre << " ";
      if (A > B)
      {
        asum += go(pre, hhmm);
      }
      else if (A < B)
      {
        bsum += go(pre, hhmm);
      }
    }
    win == 1 ? A++ : B++;
    pre = hhmm;
    // cout << "A : " << A << " B : " << B << "\n";
    // cout << "A : " << asum << " B : " << bsum << "\n";
  }
  if (A > B)
  {
    {
      asum += go(hhmm, "48:00");
    }
  }
  else if (A < B)
  {
    bsum += go(hhmm, "48:00");
  }

  cout << print(asum) << "\n"
       << print(bsum) << "\n";

  return 0;
}