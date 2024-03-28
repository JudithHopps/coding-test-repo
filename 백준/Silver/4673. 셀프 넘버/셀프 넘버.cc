#include <bits/stdc++.h>
using namespace std;
int visited[10004];

int main()
{
  for (int i = 1; i < 10004; i++)
  {
    int n = i;
    int sum = i;

    while (n)
    {
      sum += n % 10;
      n /= 10;
    }
    if (sum <= 10000 && !visited[sum])
    {
      visited[sum] = 1;
    }
  }

  for (int i = 1; i <= 10000; i++)
  {
    if (visited[i])
      continue;
    cout << i << "\n";
  }

  return 0;
}