#include <bits/stdc++.h>
using namespace std;
int n, c;
map<int, int> mp, mp2;
vector<pair<int, int>> v;

bool ch(pair<int, int> a, pair<int, int> b)
{
  if (a.second == b.second)
  {
    return mp2[a.first] < mp2[b.first];
  }
  else
  {
    return a.second > b.second;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> c;
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    mp[temp]++;
    if (mp2[temp] == 0)
      mp2[temp] = i + 1;
  }

  for (auto it : mp)
  {
    v.push_back({it.first, it.second});
  }

  sort(v.begin(), v.end(), ch);

  for (auto it : v)
  {
    for (int i = 0; i < it.second; i++)
    {
      cout << it.first << " ";
    }
  }
  return 0;
}