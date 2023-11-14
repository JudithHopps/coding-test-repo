#include <bits/stdc++.h>
using namespace std;
int n, m, a[1025][1025], tree[1025][1025], q, w, e, r, t;

void update(int y, int x, int val)
{
  int ori_x = x;
  while (y <= n)
  {
    x = ori_x;
    while (x <= n)
    {
      tree[y][x] += val;
      x += (x & -x);
    }
    y += (y & -y);
  }
  return;
}

int sum(int y, int x)
{
  int ret = 0;
  while (y > 0)
  {
    int j = x;
    while (j > 0)
    {
      ret += tree[y][j];
      j -= (j & -j);
    }
    y -= (y & -y);
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> a[i][j];
      update(i, j, a[i][j]);
    }
  }

  for (int i = 0; i < m; i++)
  {
    cin >> q >> w >> e >> r;

    if (!q)
    {
      update(w, e, r - a[w][e]);
      a[w][e] = r;
    }

    else
    {
      cin >> t;
      cout << sum(r, t) - sum(w - 1, t) - sum(r, e - 1) + sum(w - 1, e - 1) << "\n";
    }
  }
  return 0;
}