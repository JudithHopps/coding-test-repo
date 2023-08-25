#include <bits/stdc++.h>
using namespace std;
int n, t, root, ret, d;
vector<int> adj[54];

int go(int a)
{
  int cnt = 0, child = 0;
  for (int n : adj[a])
  {
    if (n == d)
      continue;
    child++;
    cnt += go(n);
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
    cin >> t;
    if (t == -1)
      root = i;
    else
    {
      adj[t].push_back(i);
    }
  }

  cin >> d;
  if (d == root)
    ret = 0;
  else
  {
    ret = go(root);
  }
  cout << ret << "\n";
  return 0;
}