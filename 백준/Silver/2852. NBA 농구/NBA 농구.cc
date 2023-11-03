#include <bits/stdc++.h>
using namespace std;
#define time tttt
#pragma warning(disable : 4996)

int n, w, pre, time, hh, mm, a, b, winA, winB;
string print(int time)
{
  string ret = to_string(time / 60) + ":";
  if (ret.size() == 2)
    ret = "0" + ret;

  string temp = to_string(time % 60);
  while (temp.size() < 2)
  {
    temp = "0" + temp;
  }
  ret += temp;
  return ret;
}
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {

    scanf("%d %d:%d", &w, &hh, &mm);
    time = hh * 60 + mm;

    if (a > b)
    {
      winA += time - pre;
    }
    if (b > a)
      winB += time - pre;

    w == 1 ? a++ : b++;

    pre = time;
  }

  if (a > b)
  {
    winA += 48 * 60 - pre;
  }
  if (b > a)
    winB += 48 * 60 - pre;

  cout << print(winA) << "\n"
       << print(winB) << "\n";

  return 0;
}