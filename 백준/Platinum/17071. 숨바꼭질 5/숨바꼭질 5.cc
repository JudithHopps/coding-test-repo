#include <bits/stdc++.h>
using namespace std;
const int MAX = 500000;
int visited[2][MAX + 2], a, b, ok, cnt = 1;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b;
  if (a == b)
  {
    cout << 0;
    return 0;
  }

  queue<int> q;
  q.push(a);
  visited[0][a] = 1;

  while (q.size())
  {
    b += cnt;
    if (b > MAX)
      break;
    if (visited[cnt % 2][b])
    {
      ok = true;
      break;
    }

    int qSize = q.size();
    for (int i = 0; i < qSize; i++)
    {
      int now = q.front();
      q.pop();
      for (int next : {now + 1, now - 1, now * 2})
      {
        if (next < 0 || next > MAX || visited[cnt % 2][next])
          continue;
        visited[cnt % 2][next] = visited[(cnt + 1) % 2][now] + 1;
        if (next == b)
        {
          ok = 1;
          break;
        }
        q.push(next);
      }
      if (ok)
        break;
    }
    if (ok)
      break;
    cnt++;
  }

  if (ok)
    cout << cnt << "\n";
  else
    cout << -1 << "\n";

  return 0;
}