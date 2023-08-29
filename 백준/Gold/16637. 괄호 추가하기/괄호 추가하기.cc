#include <bits/stdc++.h>
using namespace std;
int n, ret = -987654321;
string str;
vector<int> num;
vector<char> operStr;

int oper(int a, char b, int c)
{
  if (b == '+')
    return a + c;
  if (b == '-')
    return a - c;
  else
    return a * c;
}
void go(int idx, int sum)
{
  if (idx == num.size() - 1)
  {
    ret = max(sum, ret);
    return;
  }

  go(idx + 1, oper(sum, operStr[idx], num[idx + 1]));

  if (idx + 2 <= num.size() - 1)
  {
    int temp = oper(num[idx + 1], operStr[idx + 1], num[idx + 2]);
    go(idx + 2, oper(sum, operStr[idx], temp));
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> str;

  for (int i = 0; i < n; i++)
  {
    if (i % 2)
      operStr.push_back(str[i]);
    else
      num.push_back(str[i] - '0');
  }

  go(0, num[0]);

  cout << ret << "\n";
  return 0;
}