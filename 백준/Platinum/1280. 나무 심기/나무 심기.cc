#include <bits/stdc++.h>
using namespace std;
#define maxN 200004
typedef long long ll;

const ll mod = 1e9 + 7;
int n, val;
ll ret = 1, pre;
vector<ll> cnt(maxN, 0), tree_sum(maxN, 0);

ll psum(vector<ll> &tree, int val)
{
  ll ret = 0;
  int i = val;
  while (i)
  {
    ret += tree[i];
    i -= (i & -i);
  }
  return ret;
}

ll sum(vector<ll> &tree, int s, int e)
{
  if (s > e)
    return 0;
  return (psum(tree, e) - psum(tree, s - 1));
}

void update(vector<ll> &tree, int x, ll val)
{
  int idx = x;
  while (idx <= maxN)
  {
    tree[idx] += val;
    idx += (idx & -idx);
  }
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> val;
    val++;
    if (i != 1)
    {
      ll left = val * sum(cnt, 1, val - 1) - sum(tree_sum, 1, val - 1);
      ll right = sum(tree_sum, val + 1, maxN) - val * (sum(cnt, val + 1, maxN));
      ret *= (left + right) % mod;
      ret %= mod;
    }
    update(cnt, val, 1);
    update(tree_sum, val, val);
  }

  cout << ret << "\n";
  return 0;
}