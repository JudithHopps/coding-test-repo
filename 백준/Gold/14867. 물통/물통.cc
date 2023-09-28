#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
map<pair<int, int>, int> m;
queue<pair<int, int>> q;

void enq(int x, int y, int d)
{
  if (m[{x, y}])
    return;
  m[{x, y}] = d + 1;
  q.push({x, y});
}

int bfs(int x, int y)
{
  m[{x, y}] = 1;
  q.push({x, y});
  while (!q.empty())
  {
    x = q.front().first;
    y = q.front().second;
    q.pop();

    enq(a, y, m[{x, y}]);
    enq(x, b, m[{x, y}]);
    enq(0, y, m[{x, y}]);
    enq(x, 0, m[{x, y}]);

    enq(min(a, x + y), max(0, x + y - a), m[{x, y}]);
    enq(max(0, x + y - b), min(x + y, b), m[{x, y}]);
  }

  if (m[{c, d}])
    return m[{c, d}] - 1;
  else
    return -1;
}
// fill, empty, move
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b >> c >> d;

  cout << bfs(0, 0) << "\n";

  return 0;
}