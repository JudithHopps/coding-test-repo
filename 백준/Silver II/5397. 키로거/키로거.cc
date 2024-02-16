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
                // 첫번째인지 확인
                if (it != a.begin() && !(a.empty()))
                    it--;
            }

            else if (c == '>')
            {
                // 마지막인지 확인
                if (it != a.end() && !(a.empty()))
                    it++;
            }
            else if (c == '-')
            {
                // 시작점인지 확인
                if (it != a.begin())
                {
                    it = a.erase(--it);
                }
            }
            else
            {
                // 입력
                a.insert(it, c);
            }
        }

        for (char c : a)
        {
            cout << c;
        }
        cout << "\n";
    }
    return 0;
}