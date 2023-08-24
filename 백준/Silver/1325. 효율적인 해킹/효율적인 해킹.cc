#include <bits/stdc++.h>
using namespace std;
int n, m, ret[10004], visited[10004], a, b, mx;
vector<int> adj[10004];

int dfs(int here)
{

  int sum = 1;
  visited[here] = 1;
  for (int there : adj[here])
  {
    if (!visited[there])
    {
      sum += dfs(there);
    }
  }
  return sum;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  while (m--)
  {
    cin >> a >> b;
    adj[b].push_back(a);
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