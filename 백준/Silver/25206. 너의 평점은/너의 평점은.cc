#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <stdio.h>
#include <map>
#include <iostream>
using namespace std;

int a, b;
double sum = 0.0, cnt = 0.0; // cnt 초기화
char subject[100],c[4]; // string으로 수정

map<string, double> mp;

int main() {
	//freopen("data.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	mp["A+"] = 4.5; mp["A0"] = 4.0;
	mp["B+"] = 3.5; mp["B0"] = 3.0;
	mp["C+"] = 2.5; mp["C0"] = 2.0;
	mp["D+"] = 1.5; mp["D0"] = 1.0;
	mp["F"] = 0.0; mp["P"] = 0.0;

	for (int i = 0; i < 20; i++) {
		scanf("%s %d.%d %s", subject, &a, &b, c); // %s로 수정
		if (c[0] == 'P') continue;
		sum += a * mp[string(c)] * 1.0;
		cnt += a * 1.0;
	}

	sum /= cnt;

	printf("%.6f\n", sum );
	return 0;
}
