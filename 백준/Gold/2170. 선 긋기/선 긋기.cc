#include <bits/stdc++.h>
using namespace std;
int n, ret, from, to, r, l;
vector<pair<int, int>> v;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> from >> to;
    v.push_back({from, to});
  }
  sort(v.begin(), v.end());
  l = v[0].first, r = v[0].second;

  for (int i = 1; i < n; i++)
  {
    if (r < v[i].first)
    {
      ret += (r - l);
      l = v[i].first, r = v[i].second;
    }
    else if (r >= v[i].first && r < v[i].second)
    {
      r = v[i].second;
    }
  }
  ret += (r - l);

  cout << ret << "\n";
  return 0;
}