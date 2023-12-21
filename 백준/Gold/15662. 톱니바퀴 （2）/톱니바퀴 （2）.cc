#include <bits/stdc++.h>
using namespace std;
int t, n, a, b, ret;
string s[1004];

void rot(int pos, int dir)
{
  if (dir)
  {
    rotate(s[pos].begin(), s[pos].end() - 1, s[pos].end());
  }
  else
  {
    rotate(s[pos].begin(), s[pos].begin() + 1, s[pos].end());
  }
  return;
}
int findL(int pos)
{
  for (int i = pos; i > 0; i--)
  {
    if (s[i][6] == s[i - 1][2])
      return i;
  }
  return 0;
}

int findR(int pos)
{
  for (int i = pos; i < t - 1; i++)
  {
    if (s[i][2] == s[i + 1][6])
      return i;
  }
  return t - 1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cin >> s[i];
  }
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b;
    a--;
    b = (b == 1 ? 1 : 0);
    int dir = b;

    int l = findL(a);
    int r = findR(a);

    for (int i = a; i >= l; i--)
    {
      rot(i, dir);
      dir ^= 1;
    }
    dir = b ^ 1;
    for (int i = a + 1; i <= r; i++)
    {
      rot(i, dir);
      dir ^= 1;
    }
  }

  for (int i = 0; i < t; i++)
  {
    if (s[i][0] == '1')
      ret++;
  }
  cout << ret << "\n";
  return 0;
}