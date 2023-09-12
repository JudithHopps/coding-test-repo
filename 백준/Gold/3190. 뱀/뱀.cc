#include <bits/stdc++.h>
using namespace std;
int n, k, a[104][104], visited[104][104], x, y, l, t, cnt, dir = 1, idx;
char c;
vector<pair<int, int>> v;
deque<pair<int, int>> dq;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < k; i++)
  {
    cin >> y >> x;
    a[--y][--x] = 1;
  }
  cin >> l;
  for (int i = 0; i < l; i++)
  {
    cin >> t >> c;
    if (c == 'D')
      v.push_back({t, 1});
    else
      v.push_back({t, 3});
  }

  dq.push_back({0, 0});
  visited[0][0] = 1;

  while (dq.size())
  {
    cnt++;
    tie(y, x) = dq.front();
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx])
      break;

    if (a[ny][nx])
    {
      a[ny][nx] = 0;
    }
    else
    {
      visited[dq.back().first][dq.back().second] = 0;
      dq.pop_back();
    }

    visited[ny][nx] = 1;
    dq.push_front({ny, nx});

    if (cnt == v[idx].first)
    {
      dir = (dir + v[idx++].second) % 4;
    }
  }

  cout << cnt << "\n";
  return 0;
}