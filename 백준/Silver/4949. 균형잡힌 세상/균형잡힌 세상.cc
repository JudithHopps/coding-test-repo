#include <bits/stdc++.h>
using namespace std;
string str, ret;

string go(string str)
{
  stack<char> st;
  ret = "";
  for (char c : str)
  {
    if (c == '(')
      st.push(c);
    else if (c == ')')
    {
      if (st.size() && st.top() == '(')
        st.pop();
      else
      {
        return "no";
      }
    }
    else if (c == '[')
      st.push(c);
    else if (c == ']')
    {
      if (st.size() && st.top() == '[')
      {
        st.pop();
      }
      else
      {
        return "no";
      }
    }
  }
  if (ret == "" && st.size() == 0)
    return "yes";
  else
    return "no";
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true)
  {
    getline(cin, str);
    if (str == ".")
      break;

    cout << go(str) << "\n";
  }

  return 0;
}