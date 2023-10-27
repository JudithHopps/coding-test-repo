#include <bits/stdc++.h>
using namespace std;
int n, lis[1004], len, num;
const int INF = 1004;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(lis, lis + 1004, INF);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> num;
    auto lower_pos = lower_bound(lis, lis + len, num);
    int pos = (int)(lower_pos - lis);

    if (lis[pos] == INF)
      len++;
    lis[pos] = num;
  }
  cout << len << "\n";
  return 0;
}