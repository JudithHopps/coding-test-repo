#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ret, n, k;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  vector<pair<int, int>> v(n);
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
  priority_queue<int> pq;

  for (int i = 0; i < k; i++)
  {
    while (j < n && bag[i] >= v[j].first)
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