#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
string str; 
int i=0,mx=0;
string s[20];
int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	while (cin >> s[i]) {
		if (mx < s[i].size()) mx = s[i].size();
		i++;
	}

	/*for (int row = 0; row < i; row++) {
		cout << s[row]<<"\n";
	}*/
	for (int j = 0; j < mx; j++) {
		for (int row = 0; row < i ; row++) {
			if (s[row].size() -1 < j) continue;
			cout << s[row][j];
		}
	}
	cout << "\n";


	return 0;
}
