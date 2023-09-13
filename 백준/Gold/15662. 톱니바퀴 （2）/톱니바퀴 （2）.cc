#include <bits/stdc++.h>
using namespace std;
int n, k, a, b, ret;
string s[1004];

void rotateString(int pos, int dir)
{
  if (dir)
    rotate(s[pos].begin(), s[pos].begin() + s[pos].size() - 1, s[pos].end());
  else
    rotate(s[pos].begin(), s[pos].begin() + 1, s[pos].end());
}
int findL(int pos)
{
  for (int i = pos; i > 0; i--)
  {
    if (s[i][6] == s[i - 1][2])
    {
      return i;
    }
  }
  return 0;
}

int findR(int pos)
{
  for (int i = pos; i <= n - 2; i++)
  {
    if (s[i][2] == s[i + 1][6])
    {
      return i;
    }
  }
  return n - 1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
  }

  cin >> k;
  for (int i = 0; i < k; i++)
  {
    cin >> a >> b;
    a--;
    b = (b == 1 ? 1 : 0);
    int l = findL(a);
    int r = findR(a);

    int cnt = 1;
    for (int pos = a; pos >= l; pos--)
    {

      rotateString(pos, (cnt % 2 ? b : !b));
      cnt++;
    }
    cnt = 0;
    for (int pos = a + 1; pos <= r; pos++)
    {
      rotateString(pos, (cnt % 2 ? b : !b));
      cnt++;
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (s[i][0] == '1')
      ret++;
  }
  cout << ret << "\n";

  return 0;
}