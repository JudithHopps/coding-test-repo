#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000;
int n, k, visited[MAX + 4], cnt[MAX + 4];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  if (n == k)
  {
    cout << 0 << "\n"
         << 1 << "\n";
    return 0;
  }

  queue<int> q;
  visited[n] = 1;
  q.push({n});
  cnt[n] = 1;

  while (q.size())
  {
    int now = q.front();
    q.pop();

    for (int next : {now + 1, now - 1, now * 2})
    {
      if (next < 0 || next >= MAX)
        continue;
      if (!visited[next])
      {
        visited[next] = visited[now] + 1;
        cnt[next] += cnt[now];
        q.push(next);
      }
      else if (visited[next] == visited[now] + 1)
      {
        cnt[next] += cnt[now];
      }
    }
  }

  cout << visited[k] - 1 << "\n"
       << cnt[k];

  return 0;
}