#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, ret = INF, a[24];
string s;

void go(int start)
{
  if (start == n)
  {
    int sum = 0;
    for (int i = 1; i <= (1 << (n - 1)); i *= 2)
    {
      int cnt = 0;
      for (int j = 0; j < n; j++)
      {
        if (i & a[j])
        {
          cnt++;
        }
      }
      sum += min(cnt, n - cnt);
    }
    ret = min(sum, ret);
    return;
  }

  go(start + 1);

  a[start] = ~a[start];

  go(start + 1);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> s;
    int value = 1;
    for (int j = 0; j < n; j++)
    {
      if (s[j] == 'T')
      {
        a[i] |= value;
      }
      value *= 2;
    }
  }

  go(0);

  cout << ret << "\n";

  return 0;
}