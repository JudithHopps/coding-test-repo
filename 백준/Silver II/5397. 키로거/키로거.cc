#include <bits/stdc++.h>
using namespace std;
int t;
string str;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--)
    {
        cin >> str;

        list<char> a;
        list<char>::iterator it = a.begin();

        for (char c : str)
        {
            if (c == '<')
            {
                if (it != a.begin())
                    it--;
            }
            else if (c == '>')
            {
                if (it != a.end())
                    it++;
            }
            else if (c == '-')
            {
                if (it != a.begin())
                    it = a.erase(--it);
            }
            else
                a.insert(it, c);
        }

        for (char c : a)
        {
            cout << c;
        }
        cout << "\n";
    }

    return 0;
}
