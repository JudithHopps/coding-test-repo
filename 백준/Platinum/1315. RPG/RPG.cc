#include <bits/stdc++.h>
using namespace std;
struct game
{
  int x, y, c;
};
vector<game> a;
int n, dp[1001][1001];
bool visited[101];

int rpg(int STR, int INT)
{
  int &ret = dp[STR][INT];
  if (ret != -1)
    return ret;
  ret = 0;
  int pnt = 0;
  vector<int> v;

  for (int i = 0; i < n; i++)
  {
    if (a[i].x <= STR || a[i].y <= INT)
    {
      ret++;
      if (!visited[i])
      {
        visited[i] = 1;
        pnt += a[i].c;
        v.push_back(i);
      }
    }
  }

  for (int i = 0; i <= pnt; i++)
  {
    int nextSTR = min(1000, STR + i);
    int nextINT = min(1000, INT + (pnt - i));
    ret = max(ret, rpg(nextSTR, nextINT));
  }

  for (int vv : v)
  {
    visited[vv] = 0;
  }
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
    int j, k, l;
    cin >> j >> k >> l;
    a.push_back({j, k, l});
  }
  memset(dp, -1, sizeof(dp));
  cout << rpg(1, 1) << "\n";

  return 0;
}