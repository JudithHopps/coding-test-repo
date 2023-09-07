#include <bits/stdc++.h>
using namespace std;
int n, from, to;
vector<pair<int, int>> v;
priority_queue<int> pq;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> from >> to;
    v.push_back({to, from});
  }

  sort(v.begin(), v.end());
  from = v[0].second;
  to = v[0].first;

  for (auto it : v)
  {
    if (from <= it.second)
    {
      pq.push(it.first);
      from = pq.top();
    }
  }
  cout << pq.size() << "\n";
  return 0;
}