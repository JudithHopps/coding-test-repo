#include <iostream>
#include <cmath>

using namespace std;

const int FIRST[] = {2, 3, 5, 7};
const int NEXT[] = {1, 3, 7, 9};
int n;

bool check(int num)
{
    if (num != 2 && num % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void go(int idx, int now)
{
    if (!check(now))
    {
        return;
    }
    if (idx == n)
    {
        cout << now << "\n";
        return;
    }
    for (int i : NEXT)
    {
        go(idx + 1, now * 10 + i);
    }
}

int main()
{
    cin >> n;
    for (int f : FIRST)
    {
        go(1, f);
    }

    return 0;
}
