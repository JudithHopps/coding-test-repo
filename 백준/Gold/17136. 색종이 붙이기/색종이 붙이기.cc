#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
map<int, int> mp;
int a[10][10], ret = INF, n = 10;

bool ch(int y, int x, int siz)
{
  if (y + siz > n || x + siz > n)
    return false;
  for (int i = y; i < y + siz; i++)
  {
    for (int j = x; j < x + siz; j++)
    {
      if (a[i][j] == 0)
        return false;
    }
  }
  return true;
}

void draw(int y, int x, int siz, int val)
{
  for (int i = y; i < y + siz; i++)
  {
    for (int j = x; j < x + siz; j++)
    {
      a[i][j] = val;
    }
  }
  return;
}
void dfs(int y, int x, int cnt)
{
  if (cnt >= ret)
    return;
  if (x == n)
  {
    dfs(y + 1, 0, cnt);
    return;
  }
  if (y == n)
  {
    ret = min(ret, cnt);
    return;
  }
  if (a[y][x] == 0)
  {
    dfs(y, x + 1, cnt);
    return;
  }

  for (int i = 5; i >= 1; i--)
  {
    if (mp[i] == 5)
      continue;
    if (ch(y, x, i))
    {
      mp[i]++;
      draw(y, x, i, 0);

      dfs(y, x + i, cnt + 1);

      draw(y, x, i, 1);
      mp[i]--;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
    }
  }

  dfs(0, 0, 0);

  cout << (ret == INF ? -1 : ret) << "\n";

  return 0;
}