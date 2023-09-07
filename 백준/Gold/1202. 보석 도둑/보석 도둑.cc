#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, ret, m;
priority_queue<int> pq;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  vector<pair<ll, ll>> v(n);
  vector<int> bag(k);

  for (int i = 0; i < n; i++)
  {
    cin >> v[i].first >> v[i].second;
  }
  for (int i = 0; i < k; i++)
  {
    cin >> bag[i];
  }

  sort(v.begin(), v.end());
  sort(bag.begin(), bag.end());

  int j = 0;
  for (int i = 0; i < k; i++)
  {
    while (j < n && v[j].first <= bag[i])
    {
      pq.push(v[j++].second);
    }
    if (pq.size())
    {
      ret += pq.top();
      pq.pop();
    }
  }
  cout << ret << "\n";

  return 0;
}