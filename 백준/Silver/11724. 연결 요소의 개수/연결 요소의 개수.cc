#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int st, const vector<vector<int>>& node, vector<bool>& visited) {
	queue<int> q;
	q.push(st);
	visited[st] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < node[cur].size(); i++) {
			int next = node[cur][i];
			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> node(N + 1);
	vector<bool> visited(N + 1, false);

	int res = 0;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		node[from].push_back(to);
		node[to].push_back(from);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			bfs(i, node, visited);
			res++;
		}
	}

	cout << res << "\n";

	return 0;
}
