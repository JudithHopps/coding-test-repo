#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 4;
int n, num, lis[1000004], len;
pair<int, int> ans[1000004];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  fill(lis, lis + n, INF);
  for (int i = 0; i < n; i++)
  {
    cin >> num;
    auto lower_pos = lower_bound(lis, lis + len, num);
    int pos = (int)(lower_pos - lis);
    if (*lower_pos == INF)
    {
      len++;
    }
    *lower_pos = num;
    ans[i].first = pos;
    ans[i].second = num;
  }
  stack<int> st;
  for (int i = n - 1; i >= 0; i--)
  {
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