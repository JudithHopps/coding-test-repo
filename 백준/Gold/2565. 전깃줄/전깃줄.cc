#include <bits/stdc++.h>
using namespace std;
int n, a[104], len, lis[104];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++)
  {
    auto it = lower_bound(lis, lis + len, v[i].second);
    if (*it == 0)
    {
      len++;
    }
    *it = v[i].second;
  }
  cout << n - len;

  return 0;
}