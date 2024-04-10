#include <iostream>
using namespace std;

int main()
{
  int N;
  cin >> N;

  int m = 1;
  while (N > m)
  {
    N -= m;
    m++;
  }

  if (m % 2 == 1)
    cout << m + 1 - N << '/' << N << endl;
  else
    cout << N << '/' << m + 1 - N << endl;
}
