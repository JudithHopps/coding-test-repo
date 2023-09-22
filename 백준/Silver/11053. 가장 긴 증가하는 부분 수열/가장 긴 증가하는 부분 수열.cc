#include <bits/stdc++.h>
using namespace std;
int n, a[1004], cnt[1004], ret;
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

  for (int i = 0; i < n; i++)
  {
    int mx = 0;
    for (int j = 0; j < i; j++)
    {
      if (a[j] < a[i] && mx < cnt[j])
      {
        mx = cnt[j];
      }
    }
    cnt[i] = mx + 1;
    ret = max(cnt[i], ret);
  }
  cout << ret << "\n";
  return 0;
}