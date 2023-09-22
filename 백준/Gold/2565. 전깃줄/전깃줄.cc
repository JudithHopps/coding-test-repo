#include <bits/stdc++.h>
using namespace std;
int n, a, b, len, lis[1001];
vector<pair<int, int>> v;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++)
  {
    auto it = lower_bound(lis, lis + len, v[i].second);
    if (!(*it))
    {
      len++;
    }
    *it = v[i].second;

    // cout << *it << "\n";
  }

  cout << n - len;
  return 0;
}