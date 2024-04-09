#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,idx,temp,dp[504][504];
vector<int> v[504];

int main()
{
	//freopen("data.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n;
	for (int i = 0; i < n; i++) {
		idx++;
		for (int j = 0; j < idx; j++) {
			cin >> temp;
			v[i].push_back(temp);
		}
	}
	idx = n;
	for (int i = n-2; i >= 0; i--) {
		idx--;
		//cout << i << "\n";
		for (int j = 0; j < idx; j++) {
			//cout << v[i][j] + v[i + 1][j] << " " << v[i][j] + v[i + 1][j + 1] << "\n";
			v[i][j] = max(v[i][j] + v[i + 1][j], v[i][j] + v[i + 1][j + 1]);
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}*/


	cout << v[0][0] << "\n";
	return 0;
}
