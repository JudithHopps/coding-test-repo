#include <bits/stdc++.h>
using namespace std;
int n, x, a, ret, s, e;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  cin >> x;

  sort(v.begin(), v.end());
  e = v.size() - 1;

  while (s < e)
  {
    int i = x - v[s];
    if (v[e] < i)
    {
      s++;
    }
    else if (v[e] == i)
    {
      s++;
      e--;
      ret++;
    }
    else if (v[e] > i)
    {
      e--;
    }
  }

  cout << ret << "\n";
  return 0;
}