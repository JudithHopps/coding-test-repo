#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s, e, n, cnt[100004], a[100004], ret;

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

  while (e < n)
  {
    if (!cnt[a[e]])
    {
      cnt[a[e]]++;
      e++;
    }
    else
    {
      ret += (e - s);
      cnt[a[s++]]--;
    }
  }

  ret += (ll)(e - s) * (e - s + 1) / 2;
  cout << ret << "\n";
  return 0;
}