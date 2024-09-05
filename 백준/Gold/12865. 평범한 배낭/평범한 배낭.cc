#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;  // N: 물건의 개수, K: 배낭의 최대 무게

	vector<int> W(N + 1);  // 물건들의 무게
	vector<int> V(N + 1);  // 물건들의 가치

	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}

	// DP 테이블 선언: dp[i][w]는 i번째 물건까지 고려했을 때 배낭의 최대 무게 w일 때의 최대 가치
	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

	// DP 계산
	for (int i = 1; i <= N; i++) {
		for (int w = 0; w <= K; w++) {
			// 물건을 배낭에 넣지 않는 경우
			dp[i][w] = dp[i - 1][w];

			// 물건을 배낭에 넣는 경우
			if (w >= W[i]) {
				dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - W[i]] + V[i]);
			}
		}
	}

	// 결과 출력: 배낭에 넣을 수 있는 최대 가치
	cout << dp[N][K] << "\n";

	return 0;
}
