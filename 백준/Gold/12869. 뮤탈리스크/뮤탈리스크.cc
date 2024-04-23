#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct A {
	int a, b, c;
};
int n, a,b,c,visited[64][64][64];
int mutal[][6] = {
	{9,3,1}, {9,1,3},
	{3,9,1}, {3,1,9},
	{1,3,9}, {1,9,3}
};


int main()
{
	//freopen("data.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	cin >> a;
	if (n >= 2) cin >> b;
	if(n==3)	cin>> c;

	visited[a][b][c] = 1;

	queue<A> q;
	q.push({ a,b,c });

	while (q.size()) {
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int na = max(0, a - mutal[i][0]);
			int nb = max(0, b - mutal[i][1]);
			int nc = max(0, c - mutal[i][2]);

			if (visited[na][nb][nc]) continue;
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({ na,nb,nc });
		}
	}


	cout << visited[0][0][0] -1<< "\n";

	return 0;
}
