#include <bits/stdc++.h>
using namespace std;
int n, k, visited[200004], cnt[200004];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  if (n == k)
  {
    cout << "0\n1\n";
    return 0;
  }

  queue<int> q;
  q.push(n);
  visited[n] = 1;
  cnt[n] = 1;

  while (q.size())
  {
    int now = q.front();
    q.pop();
    for (int next : {now - 1, now + 1, now * 2})
    {
      if (next < 0 || next >= 200000)
      {
        continue;
      }
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
       << cnt[k] << "\n";

  return 0;
}