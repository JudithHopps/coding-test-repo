#include <bits/stdc++.h>
using namespace std;
int n, a[4], ret = 987654321;
struct A
{
  int dan, gi, tan, vi, price;
};
map<int, vector<vector<int>>> ans;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> a[0] >> a[1] >> a[2] >> a[3];
  vector<A> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i].dan >> v[i].gi >> v[i].tan >> v[i].vi >> v[i].price;
  }

  for (int i = 1; i < (1 << n); i++)
  {
    A temp = {0, 0, 0, 0};
    vector<int> tempV;
    for (int j = 0; j < n; j++)
    {
      if (i & (1 << j))
      {
        tempV.push_back(j + 1);
        temp.dan += v[j].dan, temp.gi += v[j].gi;
        temp.tan += v[j].tan, temp.vi += v[j].vi, temp.price += v[j].price;
      }
    }

    if (temp.dan >= a[0] && temp.gi >= a[1] && temp.tan >= a[2] && temp.vi >= a[3])
    {
      ret = min(ret, temp.price);
      ans[temp.price].push_back(tempV);
    }
  }

  if (ret != 987654321)
  {

    sort(ans[ret].begin(), ans[ret].end());
    cout << ret << "\n";
    for (int a : ans[ret][0])
    {
      cout << a << " ";
    }
  }
  else
  {
    cout << -1 << "\n";
  }

  return 0;
}