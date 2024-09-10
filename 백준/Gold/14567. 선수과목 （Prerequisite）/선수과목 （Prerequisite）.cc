#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(const int &cur, vector<vector<int>> &prerequisites, vector<int> &dp) {
	if (prerequisites[cur].size() == 0) {
		dp[cur] = 1;
	}
	else {
		int maxV = 0;
		for (int i = 1; i <= prerequisites[cur].size(); i++)
		{
			int prerequisite = prerequisites[cur][i - 1];
			if (dp[prerequisite] == -1) solve(prerequisites[cur][i], prerequisites, dp);
			maxV = max(maxV, dp[prerequisite] + 1);
		}
		dp[cur] = maxV;
	}
}

int main() {
    std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);
    
	int N, M;
	cin >> N >> M;

	vector<vector<int>> prerequisites(N+1);
	vector<int> dp(N+1, -1);

	for (int i = 1; i <= M; i++)
	{
		int A, B;
		cin >> A >> B;
		prerequisites[B].push_back(A);
	}

	for (int i = 1; i <= N ; i++)
	{
		solve(i, prerequisites, dp);
	}

	for (int i = 1; i <= N; i++)
	{
		cout << dp[i] << " ";
	}

	return 0;
}
