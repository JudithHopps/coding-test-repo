#include <bits/stdc++.h>
using namespace std;
#define prev aaa
#define next aaaa

const int MAX = 200004;
int visited[MAX], prev[MAX], n, k, ret, here, cnt, next;
vector<int> v;
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
      ret = visited[k];
      break;
    }

    for (int next : {now - 1, now + 1, now * 2})
    {
      if (next >= MAX || next < 0 || visited[next])
        continue;
      visited[next] = visited[now] + 1;
      prev[next] = now;
      q.push(next);
    }
  }

  for (int i = k; i != n; i = prev[i])
  {
    v.push_back(i);
  }
  v.push_back(n);

  cout << visited[k] - 1 << "\n";
  reverse(v.begin(), v.end());
  for (int i : v)
    cout << i << ' ';

  return 0;
}