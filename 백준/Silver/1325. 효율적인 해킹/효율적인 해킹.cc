#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, visited[10004], ret[10004], mx;
vector<int> v[10004];

int dfs(int here)
{
  visited[here] = 1;
  int ret = 1;
  for (int there : v[here])
  {
    if (visited[there])
      continue;
    ret += dfs(there);
  }
  return ret;
}

int main()
{

  cin >> n >> m;
  while (m--)
  {
    cin >> a >> b;
    v[b].push_back(a);
  }

  for (int i = 1; i <= n; i++)
  {
    fill(&visited[0], &visited[0] + 10004, 0);
    ret[i] = dfs(i);
    mx = max(mx, ret[i]);
  }

  for (int i = 1; i <= n; i++)
  {
    if (ret[i] == mx)
      cout << i << " ";
  }
  return 0;
}