#include <bits/stdc++.h>
using namespace std;
int n, m, result = 987654321, a[54][54];
vector<pair<int, int>> chicken, home;
vector<vector<int>> pick;
vector<int> v;

void combi(int start, vector<int> v)
{
  if (v.size() == m)
  {
    pick.push_back(v);
    return;
  }

  for (int i = start; i < chicken.size(); i++)
  {
    v.push_back(i);
    combi(i + 1, v);
    v.pop_back();
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
      if (a[i][j] == 1)
      {
        home.push_back({i, j});
      }
      else if (a[i][j] == 2)
      {
        chicken.push_back({i, j});
      }
    }
  }

  combi(0, v);

  for (auto ch : pick)
  {
    int sum = 0;
    for (auto h : home)
    {
      int mn = 987654321;
      for (int c : ch)
      {
        int dist = abs(h.first - chicken[c].first) + abs(h.second - chicken[c].second);
        mn = min(mn, dist);
      }
      sum += mn;
    }
    result = min(result, sum);
  }

  cout << result << "\n";
  return 0;
}