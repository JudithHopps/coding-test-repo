#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
int n, a[14], op, mn = INF, mx = -INF;
// 순열 - vector  0 1 2 3 순서로!
vector<int> v;

int oper(int a, int b, int c)
{
  if (b == 0)
  {
    return a + c;
  }
  else if (b == 1)
  {
    return a - c;
  }
  else if (b == 2)
  {
    return a * c;
  }
  else
    return a / c;
}
void go()
{
  int sum = a[0];
  for (int i = 0; i < n - 1; i++)
  {
    sum = oper(sum, v[i], a[i + 1]);
  }
  mn = min(mn, sum);
  mx = max(mx, sum);
  return;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (int i = 0; i < 4; i++)
  {
    cin >> op;
    while (op--)
    {
      v.push_back(i);
    }
  }

  do
  {
    go();
  } while (next_permutation(v.begin(), v.end()));

  cout << mx << "\n"
       << mn << "\n";

  return 0;
}