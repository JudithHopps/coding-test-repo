#include <bits/stdc++.h>
using namespace std;
int a, n, dp[5][5][100004];
vector<int> v;

int move(int cur, int next)
{
  if (cur == 0)
    return 2;
  if (cur == next)
    return 1;
  if (abs(cur - next) == 2)
    return 4;
  return 3;
}
int go(int x, int y, int cnt)
{
  if (cnt == n)
  {
    return 0;
  }
  int &ret = dp[x][y][cnt];
  if (ret != -1)
    return ret;
  int right = go(v[cnt], y, cnt + 1) + move(x, v[cnt]);
  int left = go(x, v[cnt], cnt + 1) + move(y, v[cnt]);

  return ret = min(right, left);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true)
  {
    cin >> a;
    if (a == 0)
      break;
    else
      v.push_back(a);
  }
  n = v.size();

  memset(dp, -1, sizeof(dp));

  cout << go(0, 0, 0) << "\n";

  return 0;
}