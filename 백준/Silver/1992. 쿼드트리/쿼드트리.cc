#include <bits/stdc++.h>
using namespace std;
int n;
string str;
char a[68][68];

string quard(int y, int x, int size)
{
  string ret = "";
  if (size == 1)
    return string(1, a[y][x]);

  char b = a[y][x];

  for (int i = y; i < y + size; i++)
  {
    for (int j = x; j < x + size; j++)
    {
      if (b != a[i][j])
      {
        int s = size / 2;
        ret += "(";
        ret += quard(y, x, s);
        ret += quard(y, x + s, s);
        ret += quard(y + s, x, s);
        ret += quard(y + s, x + s, s);
        ret += ")";
        return ret;
      }
    }
  }
  ret += a[y][x];
  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> str;
    for (int j = 0; j < n; j++)
    {
      a[i][j] = str[j];
    }
  }

  cout << quard(0, 0, n) << "\n";

  return 0;
}