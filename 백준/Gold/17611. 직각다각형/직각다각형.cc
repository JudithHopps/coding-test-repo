#include <bits/stdc++.h>
using namespace std;
#define y1 yyyy
vector<int> ch_X, ch_Y;
int n, x, y, y1, x1, x2, y2, _y[1000004], _x[1000004], ret;
pair<int, int> a[100004];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    x += 500000;
    y += 500000;

    a[i] = {x, y};
    ch_X.push_back(x);
    ch_Y.push_back(y);
  }

  a[n] = a[0];
  for (int i = 0; i < n; i++)
  {
    tie(x1, y1) = a[i];
    tie(x2, y2) = a[i + 1];
    if (x1 != x2)
    {
      if (x1 > x2)
        swap(x1, x2);
      for (int j = x1 + 1; j <= x2; j++)
      {
        _x[j]++;
      }
    }

    if (y1 != y2)
    {
      if (y1 > y2)
        swap(y1, y2);
      for (int j = y1 + 1; j <= y2; j++)
      {
        _y[j]++;
      }
    }
  }

  for (int a : ch_Y)
    ret = max(ret, _y[a]);
  for (int a : ch_X)
    ret = max(ret, _x[a]);
  cout << ret << "\n";
  return 0;
}