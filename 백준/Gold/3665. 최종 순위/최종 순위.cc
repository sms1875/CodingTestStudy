#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, N, M;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	cin >> T;

	while (T--) {
		cin >> N;

		vector<vector<int>> adj(N + 1);
		vector<int> degree(N + 1);
		vector<int> lastYear(N + 1);  // 작년 순위 저장

		// 작년 순위 입력
		for (int i = 1; i <= N; i++) {
			cin >> lastYear[i];
		}

		// 작년 순위에 맞춰 간선 및 진입 차수 설정
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				adj[lastYear[i]].push_back(lastYear[j]);
				degree[lastYear[j]]++;
			}
		}

		// 역전 정보 입력
		cin >> M;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;

			// a -> b 방향이 있었다면 b -> a로 뒤집어야 하고,
			// b -> a 방향이 있었다면 a -> b로 뒤집어야 함
			bool swapped = false;
			for (int j = 0; j < adj[a].size(); j++) {
				if (adj[a][j] == b) {
					adj[a].erase(adj[a].begin() + j);
					degree[b]--;
					adj[b].push_back(a);
					degree[a]++;
					swapped = true;
					break;
				}
			}

			if (!swapped) {
				for (int j = 0; j < adj[b].size(); j++) {
					if (adj[b][j] == a) {
						adj[b].erase(adj[b].begin() + j);
						degree[a]--;
						adj[a].push_back(b);
						degree[b]++;
						break;
					}
				}
			}
		}

		// 위상 정렬 수행
		queue<int> q;
		vector<int> result;

		for (int i = 1; i <= N; i++) {
			if (degree[i] == 0) {
				q.push(i);
			}
		}

		bool certain = true; // 순위가 확실한지 체크
		bool cycle = false;  // 사이클 발생 여부 체크

		for (int i = 0; i < N; i++) {
			if (q.size() == 0) {
				cycle = true; // 큐가 비어있으면 사이클 발생
				break;
			}
			if (q.size() > 1) {
				certain = false; // 큐에 여러 팀이 있으면 순위를 확정할 수 없음
			}

			int cur = q.front();
			q.pop();
			result.push_back(cur);

			for (int next : adj[cur]) {
				degree[next]--;
				if (degree[next] == 0) {
					q.push(next);
				}
			}
		}

		if (cycle) {
			cout << "IMPOSSIBLE\n";
		} else if (!certain) {
			cout << "?\n";
		} else {
			for (int x : result) {
				cout << x << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}
