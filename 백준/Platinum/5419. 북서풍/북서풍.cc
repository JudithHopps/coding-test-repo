#include <bits/stdc++.h>
using namespace std;
#define maxN 75004
typedef long long ll;
int n, a, b, t;

vector<int> tree, y;
vector<pair<int, int>> v;

int sum(int idx)
{
  int ret = 0;
  while (idx > 0)
  {
    ret += tree[idx];
    idx -= (idx & -idx);
  }
  return ret;
}

void update(int pos, int value)
{
  int idx = pos;
  // cout << "\n"
  //      << pos << "  :    ";
  while (idx <= n)
  {
    tree[idx] += value;
    idx += (idx & -idx);
    // cout << idx << "   ";
  }

  return;
}
int find_index(vector<int> &y, int value)
{
  int lo = 0, hi = y.size() - 1;
  while (lo <= hi)
  {
    int mid = (lo + hi) / 2;
    if (y[mid] == value)
      return mid;
    if (y[mid] < value)
      lo = mid + 1;
    else
      hi = mid - 1;
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  while (t--)
  {
    cin >> n;
    y.clear();
    v.clear();
    tree.clear();

    tree.resize(n + 1);

    for (int i = 0; i < n; i++)
    {
      cin >> a >> b;
      v.push_back({a, b * -1});
      y.push_back(b * -1);
    }

    sort(v.begin(), v.end());
    sort(y.begin(), y.end());

    ll ret = 0;
    update(find_index(y, v[0].second) + 1, 1);

    for (int i = 1; i < n; i++)
    {
      int idx = find_index(y, v[i].second) + 1;
      ret += 1LL * sum(idx);
      update(idx, 1);
    }

    cout << ret << "\n";
  }

  return 0;
}