#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// LCS의 길이를 찾고, 해당 LCS를 재구성하는 함수
string findLCS(string &A, string &B) {
	int n = A.size(), m = B.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	// DP를 이용해 LCS 길이 계산
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	// dp 배열을 역추적하여 LCS를 재구성
	string lcs = "";
	int i = n, j = m;
	while (i > 0 && j > 0) {
		if (A[i - 1] == B[j - 1]) {
			lcs += A[i - 1];
			--i; --j;
		}
		else if (dp[i - 1][j] > dp[i][j - 1]) {
			--i;
		}
		else {
			--j;
		}
	}

	reverse(lcs.begin(), lcs.end());
	return lcs;
}

int main() {
	string A, B;
	//cout << "첫 번째 문자열을 입력하세요: ";
	cin >> A;
	//cout << "두 번째 문자열을 입력하세요: ";
	cin >> B;

	string lcs = findLCS(A, B);
	//cout << "LCS: " << lcs << endl;
	cout << lcs.size() << "\n";
	return 0;
}
