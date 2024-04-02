#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n1, n2;
string s1,s2;
int main() {
	cin >> s1 >> s2;

	for (int i = s1.size() - 1; i >= 0; i--) {
		n1 = n1 * 10 + s1[i] - '0';
	}
	for (int i = s2.size() - 1; i >= 0; i--) {
		n2 = n2 * 10 + s2[i] - '0';
	}

	cout << max(n1, n2) << "\n";
	return 0;
}