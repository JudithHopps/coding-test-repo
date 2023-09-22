#include <bits/stdc++.h>
using namespace std;
int n, a[1001], cnt[1001], pre[1001], ret=1, idx;

void go(int idx)
{
  if (idx == -1)
    return;
  go(pre[idx]);
  cout << a[idx] << " ";
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  fill(pre, pre + 1001, -1);
  fill(cnt, cnt + 1001, 1);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (a[i] > a[j] && cnt[i] < cnt[j] + 1)
      {
        cnt[i] = cnt[j] + 1;
        pre[i] = j;
        if (cnt[i] > ret)
        {
          ret = cnt[i];
          idx = i;
        }
      }
    }
  }

  cout << ret << "\n";
  go(idx);

  return 0;
}