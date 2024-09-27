#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
using namespace std;

int r, c, k;
int a[104][104];  // 입력 배열
int n = 3, m = 3; // 초기 배열 크기
int ret = -1;

// 사용자 정의 비교 함수 객체
struct cmp {
    bool operator()(pair<int, int> A, pair<int, int> B) {
        if (A.second != B.second) return A.second > B.second;  // 등장 횟수 기준 오름차순
        return A.first > B.first;  // 숫자 기준 오름차순
    }
};

// 정렬된 행/열 데이터를 priority_queue로 변환
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> getSortedQueue(map<int, int>& mp) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (auto it : mp) {
        pq.push({it.first, it.second});
    }
    return pq;
}

// R 연산
void rotR() {
    int b[104][104] = {0};  // 임시 배열
    int maxColLen = 0;  // 각 행의 최대 열 길이

    for (int i = 1; i <= n; i++) {
        map<int, int> mp;
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) continue;  // 0은 무시
            mp[a[i][j]]++;
        }

        // 정렬된 데이터를 우선순위 큐로 받기
        auto pq = getSortedQueue(mp);

        int idx = 0;
        while (!pq.empty() && idx < 100) {  // 최대 100개까지만 저장
            b[i][++idx] = pq.top().first;
            b[i][++idx] = pq.top().second;
            pq.pop();
        }

        maxColLen = max(maxColLen, idx);  // 현재 행의 최대 길이 갱신
    }

    m = maxColLen;  // 최대 열 길이 업데이트
    memcpy(a, b, sizeof(a));  // 배열 갱신
}

// C 연산
void rotC() {
    int b[104][104] = {0};  // 임시 배열
    int maxRowLen = 0;  // 각 열의 최대 행 길이

    for (int j = 1; j <= m; j++) {
        map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            if (a[i][j] == 0) continue;  // 0은 무시
            mp[a[i][j]]++;
        }

        // 정렬된 데이터를 우선순위 큐로 받기
        auto pq = getSortedQueue(mp);

        int idx = 0;
        while (!pq.empty() && idx < 100) {  // 최대 100개까지만 저장
            b[++idx][j] = pq.top().first;
            b[++idx][j] = pq.top().second;
            pq.pop();
        }

        maxRowLen = max(maxRowLen, idx);  // 현재 열의 최대 길이 갱신
    }

    n = maxRowLen;  // 최대 행 길이 업데이트
    memcpy(a, b, sizeof(a));  // 배열 갱신
}

// 재귀적으로 연산 수행
void go(int cnt) {
    if (cnt > 100) return;  // 최대 100초 초과 시 종료
    if (a[r][c] == k) {     // 원하는 값이 있는 경우 종료
        ret = cnt;
        return;
    }

    // 조건에 따라 R 연산 또는 C 연산 수행
    if (n >= m) rotR();
    else rotC();

    go(cnt + 1);  // 재귀 호출
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 초기 값 입력
    cin >> r >> c >> k;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> a[i][j];
        }
    }

    // 연산 시작
    go(0);

    // 결과 출력
    cout << ret << "\n";
    return 0;
}
