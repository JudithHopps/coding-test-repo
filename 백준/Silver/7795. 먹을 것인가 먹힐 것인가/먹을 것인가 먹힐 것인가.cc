#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, m, ret;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    vector<int> a(n), b(m);
    ret = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
      cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++)
    {
      auto l = lower_bound(b.begin(), b.end(), a[i]);
      ret += (int)(l - b.begin());
    }
    cout << ret << "\n";
  }

  return 0;
}