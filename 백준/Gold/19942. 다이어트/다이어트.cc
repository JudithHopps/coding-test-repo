#include <bits/stdc++.h>
using namespace std;
int n, k, sum = 987654321, a[20][10];
vector<int> inge;
map<int, vector<vector<int>>> mp;
vector<vector<int>> ret;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  int cnt = 4;
  while (cnt--)
  {
    cin >> k;
    inge.push_back(k);
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < (1 << n); i++)
  {
    int price = 0;
    int material[4] = {0, 0, 0, 0};
    vector<int> v;

    for (int j = 0; j < n; j++)
    {
      if (i & (1 << j))
      {
        for (int p = 0; p < 4; p++)
        {
          material[p] += a[j][p];
        }
        price += a[j][4];
        v.push_back(j + 1);
      }
    }
    // cout << i << "  price : " << price << "   " << material[0] << "\n";
    bool flag = true;
    for (int k = 0; k < 4; k++)
    {
      if (material[k] < inge[k])
      {
        flag = false;
        break;
      }
    }
    if (flag)
    {
      sum = min(sum, price);
      mp[price].push_back(v);
    }
  }

  if (sum == 987654321)
  {
    cout << -1 << "\n";
    return 0;
  }

  cout << sum << "\n";

  sort(mp[sum].begin(), mp[sum].end());

  for (int i : mp[sum][0])
  {
    cout << i << " ";
  }

  return 0;
}