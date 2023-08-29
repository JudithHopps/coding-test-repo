#include <bits/stdc++.h>
using namespace std;
const int MAX = 200004;
#define prev aaaa
int n, k, visited[MAX], prev[MAX];
queue<int> q;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  visited[n] = 1;
  q.push(n);

  while (q.size())
  {
    int now = q.front();
    q.pop();
    if (now == k)
    {
      break;
    }
    for (int next : {now - 1, now + 1, now * 2})
    {
      if (next < 0 || next >= MAX || visited[next])
        continue;
      visited[next] = visited[now] + 1;
      prev[next] = now;
      q.push(next);
    }
  }
  vector<int> v;
  for (int i = k; i != n; i = prev[i])
  {
    v.push_back(i);
  }
  v.push_back(n);
  reverse(v.begin(), v.end());

  cout << visited[k] - 1 << "\n";

  for (int n : v)
  {
    cout << n << " ";
  }

  return 0;
}