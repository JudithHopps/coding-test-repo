#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxN = 200004, mod = 1e9 + 7;
vector<ll> cnt(maxN, 0), sum(maxN, 0);
int n, val;
ll ret = 1;

void update(vector<ll> &tree, int idx, int val)
{
  while (idx <= maxN)
  {
    tree[idx] += val;
    idx += (idx & -idx);
  }
  return;
}
ll psumFn(vector<ll> &tree, int idx)
{
  ll sum = 0;
  while (idx)
  {
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}
ll sumFn(vector<ll> &tree, int s, int e)
{
  return psumFn(tree, e) - psumFn(tree, s - 1);
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
      ll left = val * sumFn(cnt, 1, val - 1) - sumFn(sum, 1, val - 1);
      ll right = sumFn(sum, val + 1, maxN) - val * sumFn(cnt, val + 1, maxN);

      ret *= (left + right) % mod;
      ret %= mod;
    }

    update(cnt, val, 1);
    update(sum, val, val);
  }

  cout << ret << "\n";

  return 0;
}