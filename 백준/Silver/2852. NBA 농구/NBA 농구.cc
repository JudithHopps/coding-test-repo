#include <bits/stdc++.h>
using namespace std;
int n, a, b, cur, asum, bsum;
string hhmm, pre;
// 1. hhmm -> mm으로 계산 -> a,b 득점 비교 후 이기고 있는 분 계산
string print(int sum)
{
  string hh = "00" + to_string(sum / 60);
  string mm = "00" + to_string(sum % 60);
  return hh.substr(hh.size() - 2, 2) + ":" + mm.substr(mm.size() - 2, 2);
}
int cnt(string a, string b)
{
  int acnt = atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
  int bcnt = atoi(b.substr(0, 2).c_str()) * 60 + atoi(b.substr(3, 2).c_str());
  return bcnt - acnt;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  while (n--)
  {
    cin >> cur >> hhmm;
    if (a > b)
      asum += cnt(pre, hhmm);
    if (b > a)
      bsum += cnt(pre, hhmm);

    cur == 1 ? a++ : b++;

    pre = hhmm;
  }

  if (a > b)
    asum += cnt(hhmm, "48:00");
  if (b > a)
    bsum += cnt(hhmm, "48:00");

  cout << print(asum) << "\n"
       << print(bsum) << "\n";

  return 0;
}
