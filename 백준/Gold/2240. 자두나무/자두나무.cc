#include <bits/stdc++.h>
using namespace std;
int t, w, ret, a[1004], dp[1004][2][34];

int go(int idx, int tree, int cnt)
{
  if (cnt < 0)
    return -1e9;
  if (idx == t)
    return cnt == 0 ? 0 : -1e9;
  int &ret = dp[idx][tree][cnt];
  if (ret != -1)
  {
    // cout << "~ret : " << ~ret << "  ret : " << ret << " \n";
    return ret;
  }
  return ret = (max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt))) + (tree == a[idx] - 1);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(dp, -1, sizeof(dp));
  cin >> t >> w;
  for (int i = 0; i < t; i++)
  {
    cin >> a[i];
  }
  cout << max(go(0, 1, w - 1), go(0, 0, w)) << "\n";
  return 0;
}