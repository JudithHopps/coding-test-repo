#include <bits/stdc++.h>
using namespace std;
const int MAX = 500000;
int n, k, cnt, visited[2][MAX + 4];
bool ok;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  visited[0][n] = 1;
  queue<int> q;
  q.push(n);

  if (n == k)
  {
    cout << 0 << "\n";
    return 0;
  }

  while (q.size())
  {
    cnt++;
    k += cnt;
    if (k > MAX)
    {
      ok = false;
      break;
    }

    if (visited[cnt % 2][k])
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
        if (next == k)
        {
          ok = true;
          break;
        }
        visited[cnt % 2][next] = visited[(cnt + 1) % 2][now] + 1;
        q.push(next);
      }
      if (ok)
      {
        break;
      }
    }
    if (ok)
    {
      break;
    }
  }

  cout << (ok ? cnt : -1) << "\n";

  return 0;
}