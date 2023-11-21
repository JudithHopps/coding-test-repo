#include <bits/stdc++.h>
using namespace std;
#define time tttt
int n, k, id, cost_time, time, idx;
long long ret;
struct Casher
{
  int id, maxTime, casher;
};
struct cmp
{
  bool operator()(Casher &a, Casher &b)
  {
    if (a.maxTime == b.maxTime)
    {
      return a.casher > b.casher;
    }
    return a.maxTime > b.maxTime;
  }
};
bool cmp2(Casher a, Casher b)
{
  if (a.maxTime == b.maxTime)
  {
    return a.casher > b.casher;
  }
  else
    return a.maxTime < b.maxTime;
}
priority_queue<Casher, vector<Casher>, cmp> pq;
vector<Casher> v;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> id >> cost_time;
    if (i < k)
    {
      pq.push({id, cost_time, i + 1});
      continue;
    }
    pq.push({id, cost_time + pq.top().maxTime, pq.top().casher});
    v.push_back(pq.top());
    pq.pop();
  }

  while (pq.size())
  {
    v.push_back(pq.top());
    pq.pop();
  }
  sort(v.begin(), v.end(), cmp2);

  for (int i = 0; i < v.size(); i++)
  {
    ret += 1LL * (i + 1) * v[i].id;
  }

  cout << ret << "\n";

  return 0;
}