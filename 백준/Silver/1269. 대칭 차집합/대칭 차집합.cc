#include <bits/stdc++.h>
using namespace std;
int n, m, a, ret;
vector<int> v;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  v.resize(n + m);

  for (int i = 0; i < n + m; i++)
  {
    cin >> a;
    v[i] = a;
  }

  sort(v.begin(), v.end());

  // 1 2 2 3 4 4 5 6
  for (int i = 0; i < v.size(); i++)
  {
    if (i == v.size() - 1)
      ret++;
    if (i != v.size() - 1 && v[i] != v[i + 1])
    {
      ret++;
    }
    else
      i++;
  }

  cout << ret << "\n";
  return 0;
}