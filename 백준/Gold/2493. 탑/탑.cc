#include <bits/stdc++.h>
using namespace std;
int n, a[500004], ret[500004];
stack<pair<int, int>> st;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        while (st.size() && st.top().second < a[i])
        {
            st.pop();
        }
        if (st.size() && st.top().second > a[i])
        {
            ret[i] = st.top().first;
        }
        st.push({i, a[i]});
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ret[i] << " ";
    }
    return 0;
}
