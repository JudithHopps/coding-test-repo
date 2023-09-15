#include <bits/stdc++.h>
using namespace std;
int a[1001], b[1001], ret, asum[2002], bsum[2002], want, n, m;
map<int, int> aCnt, bCnt;

void make(int n, int psum[], map<int, int> &mp)
{
  for (int interval = 1; interval <= n; interval++)
  {
    for (int start = interval; start <= n + interval - 1; start++)
    {
      int sum = psum[start] - psum[start - interval];
      mp[sum]++;
      if (interval == n)
        break;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> want >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    asum[i] = asum[i - 1] + a[i];
  }
  for (int i = n + 1; i <= 2 * n; i++)
  {
    // cout << "origin : " << asum[i] << "new : ";
    asum[i] = asum[i - 1] + a[i - n];
    // cout << asum[i] << "\n";
  }

  for (int i = 1; i <= m; i++)
  {
    cin >> b[i];
    bsum[i] = bsum[i - 1] + b[i];
  }
  for (int i = m + 1; i <= 2 * m; i++)
  {
    bsum[i] = bsum[i - 1] + b[i - m];
  }
  make(n, asum, aCnt);
  make(m, bsum, bCnt);
  ret = (aCnt[want] + bCnt[want]);

  for (int i = 1; i < want; i++)
  {
    ret += (aCnt[i] * bCnt[want - i]);
  }
  cout << ret;

  return 0;
}