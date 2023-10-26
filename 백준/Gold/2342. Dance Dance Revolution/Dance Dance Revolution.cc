#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000004
int n, dp[5][5][MAX_N], num;
vector<int> v;

int ch(int from, int to)
{
  if (from == 0)
    return 2;
  if (from == to)
    return 1;
  if (abs(from - to) == 2)
    return 4;
  return 3;
}
int go(int y, int x, int cnt)
{
  if (cnt == num)
  {
    return 0;
  }
  if (dp[y][x][cnt] != -1)
    return dp[y][x][cnt];
  int right = go(v[cnt], x, cnt + 1) + ch(y, v[cnt]);
  int left = go(y, v[cnt], cnt + 1) + ch(x, v[cnt]);
  return dp[y][x][cnt] = min(right, left);
}
int main()
{
  while (true)
  {
    scanf("%d", &n);
    if (n == 0)
      break;
    v.push_back(n);
  }
  num = v.size();

  memset(dp, -1, sizeof(dp));

  cout << go(0, 0, 0) << "\n";

  return 0;
}