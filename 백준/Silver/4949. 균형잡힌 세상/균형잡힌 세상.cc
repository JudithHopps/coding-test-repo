#include <bits/stdc++.h>
using namespace std;
string s;

bool ch(string s)
{
  stack<char> st;
  for (char c : s)
  {
    if (c == '(' || c == '[')
      st.push(c);
    else if (c == ')')
    {
      if (st.size() && st.top() == '(')
        st.pop();
      else
        return false;
    }
    else if (c == ']')
    {
      if (st.size() && st.top() == '[')
        st.pop();
      else
        return false;
    }
  }

  if (st.size() == 0)
    return true;
  return false;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true)
  {
    getline(cin, s);
    if (s == ".")
      break;
    if (ch(s))
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}