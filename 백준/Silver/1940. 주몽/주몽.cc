#include <bits/stdc++.h>
using namespace std;
int n, k, temp, l, r, ret;
vector<int> v;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    v.push_back(temp);
  }

  sort(v.begin(), v.end());
  l = 0, r = n - 1;

  while (l < r)
  {
    int sum = v[l] + v[r];
    if (sum == k)
    {
      ret++;
      l++, r--;
    }
    else if (sum > k)
    {
      r--;
    }
    else
    {
      l++;
    }
  }

  cout << ret << "\n";

  return 0;
}