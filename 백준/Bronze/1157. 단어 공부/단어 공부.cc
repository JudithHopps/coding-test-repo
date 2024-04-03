#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int mx,cnt;
string str;
map<char, int > mp;
char c;

int main() {
	cin >> str;

	for (char c : str) {
		mp[(char)toupper(c)]++;
		mx = max(mx, mp[(char)toupper(c)]);
	}

	for (auto it : mp) {
		if (it.second == mx) {
			cnt++;
			c = it.first;
		}
	}

	cout << (cnt == 1 ? (char)toupper(c) : '?') << "\n";


	return 0;
}
