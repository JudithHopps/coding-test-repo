#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int ret;
string s;
map<char, int> mp;
int main() {
	cin >> s;
	mp['A'] = 4; mp['B'] = 4; mp['C'] = 4;
	mp['D'] = 5; mp['E'] = 5; mp['F'] = 5;
	mp['G'] = 6; mp['H'] = 6; mp['I'] = 6;
	mp['J'] = 7; mp['K'] = 7; mp['L'] = 7;
	mp['M'] = 8; mp['N'] = 8; mp['O'] = 8;
	mp['P'] = 9; mp['Q'] = 9; mp['R'] = 9; mp['S'] = 9;
	mp['T'] = 10; mp['U'] = 10; mp['V'] = 10;
	mp['W'] = 11; mp['X'] = 11; mp['Y'] = 11; mp['Z'] = 11;

	for (char c : s) {
		ret += mp[c]-1;
	}
	cout << ret << "\n";
	return 0;
}