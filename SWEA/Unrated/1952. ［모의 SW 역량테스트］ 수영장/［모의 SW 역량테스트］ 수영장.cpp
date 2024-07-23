#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		int oneDay, oneMonth, threeMonth, oneYear;
		int month[12];

		cin >> oneDay >> oneMonth >> threeMonth >> oneYear;
		for (int i = 0; i < 12; i++) {
			cin >> month[i];
		}

		int dp[13] = { 0 }; // dp[i]는 i번째 달까지의 최소 비용

		for (int i = 0; i < 12; i++) {
			// 1일 이용권 사용
			dp[i + 1] = dp[i] + month[i] * oneDay;
			// 1달 이용권 사용
			dp[i + 1] = min(dp[i + 1], dp[i] + oneMonth);
			// 3달 이용권 사용
			if (i >= 2) {
				dp[i + 1] = min(dp[i + 1], dp[i - 2] + threeMonth);
			}
			else {
				dp[i + 1] = min(dp[i + 1], threeMonth);
			}
		}

		// 1년 이용권 사용
		int result = min(dp[12], oneYear);

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}