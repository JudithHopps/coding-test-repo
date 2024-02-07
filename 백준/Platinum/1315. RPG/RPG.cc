#include <bits/stdc++.h>
using namespace std;
int n, s, i, p, visited[54], dp[1004][1004];
struct game
{
  int s, i, p;
};
vector<game> v;

int go(int STR, int INT)
{
  int &ret = dp[STR][INT];
  if (ret != -1)
    return ret;
  ret = 0;
  int p = 0;
  vector<int> temp;

  for (int i = 0; i < n; i++)
  {
    if (  v[i].i <= INT || v[i].s <= STR)
    {
      ret++;
      if (!visited[i])
      {
        visited[i] = 1;
        temp.push_back(i);
        p += v[i].p;
      }
    }
  }

  for (int i = 0; i <= p; i++)
  {
    int nextS = min(1000, STR + i);
    int nextI = min(1000, INT + (p - i));

    ret = max(ret, go(nextS, nextI));
  }

  for (int tt : temp)
  {
    visited[tt] = 0;
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(dp, -1, sizeof(dp));

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int j, k, l;
    cin >> j >> k >> l;
    v.push_back({j, k, l});
  }

  cout << go(1, 1) << "\n";

  return 0;
}