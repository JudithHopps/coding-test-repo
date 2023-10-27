#include <bits/stdc++.h>
using namespace std;
#define mx_N 1000004
const int INF = 1e9 + 4;

int n, num, lis[mx_N], len;
stack<int> st;
pair<int, int> ans[mx_N];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(lis, lis + mx_N, INF);
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> num;
    auto lower_pos = lower_bound(lis, lis + len, num);
    int pos = (int)(lower_pos - lis);
    if (lis[pos] == INF)
      len++;
    lis[pos] = num;
    ans[i].first = pos;
    ans[i].second = num;
  }

  for (int i = n - 1; i >= 0; i--)
  {
    // cout << ans[i].first << " , " << ans[i].second << "\n";
    if (ans[i].first == len - 1)
    {
      st.push(ans[i].second);
      len--;
    }
  }
  cout << st.size() << "\n";
  while (st.size())
  {
    cout << st.top() << " ";
    st.pop();
  }

  return 0;
}