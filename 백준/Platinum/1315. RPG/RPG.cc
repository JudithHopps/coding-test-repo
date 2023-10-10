#include <bits/stdc++.h>
using namespace std;
struct game
{
  int s, i, p;
};
vector<game> v;
int n, s, l, p, dp[1001][1001];
bool visited[54];

int go(int STR, int INT)
{
  int &ret = dp[STR][INT];
  if (ret != -1)
    return ret;

  ret = 0;
  int pnt = 0;
  vector<int> a;

  for (int i = 0; i < n; i++)
  {
    if (v[i].s <= STR || v[i].i <= INT)
    {
      ret++;
      if (!visited[i])
      {
        visited[i] = 1;
        pnt += v[i].p;
        a.push_back(i);
      }
    }
  }

  for (int i = 0; i <= pnt; i++)
  {
    int nextSTR = min(1000, STR + i);
    int nextINT = min(1000, INT + pnt - i);
    ret = max(ret, go(nextSTR, nextINT));
  }

  for (int i : a)
  {
    visited[i] = 0;
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
    cin >> s >> l >> p;
    v.push_back({s, l, p});
  }
  memset(dp, -1, sizeof(dp));

  cout << go(1, 1) << "\n";

  return 0;
}