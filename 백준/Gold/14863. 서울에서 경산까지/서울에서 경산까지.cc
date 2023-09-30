#include <bits/stdc++.h>
using namespace std;
int n, k, ret, t;
#define time tttt
vector<int> a[104];

void go(int idx, int time, int sum)
{
  if (time > k)
    return;
  if (idx == n)
  {
    ret = max(ret, sum);
    return;
  }
  go(idx + 1, time + a[idx][0], sum + a[idx][1]);
  go(idx + 1, time + a[idx][2], sum + a[idx][3]);
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cin >> t;
      a[i].push_back(t);
    }
  }

  go(0, 0, 0);
  cout << ret << "\n";

  return 0;
}