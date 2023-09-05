#include <bits/stdc++.h>
using namespace std;
int n, node, m, a, b;
int visited[1004];
vector<int> adj[1004];

void dfs(int a)
{
  if (visited[a])
    return;
  visited[a] = 1;
  for (int there : adj[a])
  {
    if (!visited[there])
    {
      dfs(there);
    }
  }
  return;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  while (n--)
  {
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    for (int i = 0; i < 1004; i++)
      adj[i].clear();

    cin >> node >> m;
    for (int i = 0; i < m; i++)
    {
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    for (int i = 1; i <= node; i++)
    {
      if (!visited[i])
      {
        cnt++;
        dfs(i);
      }
    }

    cout << (cnt == 1 && m == node - 1 ? "tree" : "graph") << "\n";
  }

  return 0;
}