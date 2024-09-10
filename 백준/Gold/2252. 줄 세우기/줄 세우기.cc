#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	cin >> N >> M;

	vector<vector<int>> adj(N + 1);
	vector<int> degree(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		degree[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		cout << cur << " ";

		for (int next : adj[cur])
		{
			degree[next]--;
			if (degree[next] == 0) {
				q.push(next);
			}
		}
	}

	return 0;
}
