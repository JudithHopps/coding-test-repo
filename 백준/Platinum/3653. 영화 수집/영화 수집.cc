#include <bits/stdc++.h>
using namespace std;
int t, n, m, tree[200004], temp;
map<int, int> mp;

void update(int idx, int val)
{
  while (idx <= 200004)
  {
    tree[idx] += val;
    idx += (idx & -idx);
  }
  return;
}
int sum(int idx)
{
  int ret = 0;
  while (idx)
  {
    ret += tree[idx];
    idx -= (idx & -idx);
  }
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    memset(tree, 0, sizeof(tree));
    mp.clear();

    int mx = 100001;
    for (int i = 1; i <= n; i++)
    {
      update(mx + i, 1);
      mp[i] = mx + i;
    }

    for (int i = 0; i < m; i++)
    {
      cin >> temp;
      int idx = mp[temp];
      cout << sum(idx) - 1 << " ";

      update(idx, -1);
      update(--mx, 1);
      mp[temp] = mx;
    }

    cout << "\n";
  }

  return 0;
}