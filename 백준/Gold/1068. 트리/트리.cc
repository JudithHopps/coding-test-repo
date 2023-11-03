#include <bits/stdc++.h>
using namespace std;
int n, a, m, root;
vector<int> adj[54];

int go(int here)
{
  int cnt = 0, child = 0;
  for (int aa : adj[here])
  {
    if (aa == m)
      continue;
    child++;
    cnt += go(aa);
  }
  if (child == 0)
    return 1;
  return cnt;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    if (a == -1)
      root = i;
    else
      adj[a].push_back(i);
  }

  cin >> m;

  if (m == root)
    cout << 0 << "\n";
  else
  {
    cout << go(root) << "\n";
  }

  return 0;
}