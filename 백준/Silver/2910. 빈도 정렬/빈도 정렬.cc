#include <bits/stdc++.h>
using namespace std;
int n, c, temp;
map<int, int> mp, order;
vector<int> v;

bool ch(int a, int b)
{
  if (mp[a] == mp[b])
  {
    return order[a] < order[b];
  }

  return mp[a] > mp[b];
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> c;

  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    if (mp[temp] == 0)
      order[temp] = i;
    mp[temp]++;
    v.push_back(temp);
  }

  sort(v.begin(), v.end(), ch);

  for (int i : v)
  {
    cout << i << " ";
  }
  cout << "\n";

  return 0;
}