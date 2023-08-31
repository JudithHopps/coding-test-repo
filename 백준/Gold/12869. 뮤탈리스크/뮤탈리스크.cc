#include <bits/stdc++.h>
using namespace std;
int n, a[3], visited[64][64][64];
vector<int> v = {1, 3, 9};
vector<vector<int>> attack;

struct A
{
  int a, b, c;
};

int bfs(int a, int b, int c)
{
  visited[a][b][c] = 1;
  queue<A> q;
  q.push({a, b, c});

  while (q.size())
  {
    int a = q.front().a;
    int b = q.front().b;
    int c = q.front().c;
    q.pop();

    for (int i = 0; i < attack.size(); i++)
    {
      int na = max(0, a - attack[i][0]);
      int nb = max(0, b - attack[i][1]);
      int nc = max(0, c - attack[i][2]);

      if (visited[na][nb][nc])
        continue;
      visited[na][nb][nc] = visited[a][b][c] + 1;
      q.push({na, nb, nc});
    }
  }

  return visited[0][0][0] - 1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  do
  {
    attack.push_back(v);
  } while (next_permutation(v.begin(), v.end()));

  cout << bfs(a[0], a[1], a[2]) << "\n";
  return 0;
}
