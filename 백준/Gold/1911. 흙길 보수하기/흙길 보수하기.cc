#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, l, ret, idx, b;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> l;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i].first >> v[i].second;
  }
   sort(v.begin(),v.end());
  for (int i = 0; i < n; i++)
  {
    if (v[i].second <= idx)continue;
    if (idx < v[i].first)
    {
      b = (v[i].second - v[i].first) / l + ((v[i].second - v[i].first) % l ? 1 : 0);
      idx = v[i].first + b * l;
    }
    else
    {
      b = (v[i].second - idx) / l + ((v[i].second - idx) % l ? 1 : 0);
      idx += (b * l);
    }
    ret += b;
  }
  cout << ret << "\n";

  return 0;
}