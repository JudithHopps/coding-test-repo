#include <iostream>
#include <algorithm>
using namespace std;
const int n = 10,INF = 987654321;
int a[14][14], ret = INF, visited[14][14],sy,sx, cnt[10];
// 1이 적힌 칸은 모두 색종이로 덮여져야 한다
// 1×1, 2×2, 3×3, 4×4, 5×5 종류의 색종이는 5개씩 가지고 있다.
bool flag = false;

bool ch(int y,int x ,int siz) {
	if (y + siz > n || x + siz > n) return false;

	for (int ny = y; ny < y + siz; ny++) {
		for (int nx = x; nx < x + siz; nx++) {
			if (a[ny][nx] != 1) {
				return false;
			}
		}
	}
	return true;
}
void paint(int y, int x, int siz, int val) {
	for (int ny = y; ny < y + siz; ny++) {
		for (int nx = x; nx < x + siz; nx++) {
			a[ny][nx] = val;
		}
	}
}

void go(int y, int x, int use) {
	if (ret <= use) return;
	if (y >= n) {
		ret = min(ret, use);
		return;
	}
	if (x >= n) {
		go(y + 1, 0, use);
		return;
	}
	if (a[y][x] == 0) {
		go(y, x + 1, use);
		return;
	}

	for (int siz = 5; siz >= 1; siz--) {
		if (cnt[siz] == 5) continue;
		if (!ch(y, x, siz)) continue;
		cnt[siz]++;
		paint(y, x, siz, 0); // 색종이 덮기
		go(y, x + 1, use + 1);
		paint(y, x, siz, 1); // 색종이 제거
		cnt[siz]--;
	}
}

int main()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] && !flag) {
				flag = true;
				sy = i; sx = j;
			}
		}
	}

	go(sy,sx, 0);

	cout << (ret==INF? -1 : ret) << "\n";
	return 0;
}
