#include <bits/stdc++.h>
using namespace std;
int t, w, a[1004], dp[1004][2][34], cur = 1, ret;

int go(int idx, int cur, int cnt)
{
  if (idx == t)
    return 0;

  int &ret = dp[idx][cur][cnt];
  if (ret != -1)
    return ret;
  ret = 0;
  int now = (cur == a[idx] ? 1 : 0);
  if (cnt != w)
  {
    ret = max(ret, go(idx + 1, cur ^ 1, cnt + 1) + now);
  }
  ret = max(ret, go(idx + 1, cur, cnt) + now);

  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t >> w;
  for (int i = 0; i < t; i++)
  {
    cin >> a[i];
    a[i]--;
  }

  memset(dp, -1, sizeof(dp));
  cout << max(go(0, 0, 0), go(0, 1, 1)) << "\n";

  return 0;
}