#include <bits/stdc++.h>
using namespace std;
int n;
double num, temp, ret;

int main()
{

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    cin >> num;
    if (num * temp < num)
    {
      temp = num;
    }
    else
    {
      temp *= num;
    }
    ret = max(ret, temp);
  }
  printf("%.3lf", ret);

  return 0;
}