#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

string bfs(int start, int target) {
	queue<pair<int, string>> q;
	vector<bool> visited(10000, false);  // 각 숫자에 대한 방문 여부를 기록

	q.push({ start, "" });
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		string op = q.front().second;
		q.pop();

		// 목표 숫자에 도달했을 때
		if (cur == target) {
			return op;
		}

		int next;

		// D 연산
		next = (cur * 2) % 10000;
		if (!visited[next]) {
			visited[next] = true;
			q.push({ next, op + "D" });
		}

		// S 연산
		next = cur == 0 ? 9999 : cur - 1;
		if (!visited[next]) {
			visited[next] = true;
			q.push({ next, op + "S" });
		}

		// L 연산
		next = (cur % 1000) * 10 + (cur / 1000);
		if (!visited[next]) {
			visited[next] = true;
			q.push({ next, op + "L" });
		}

		// R 연산
		next = (cur % 10) * 1000 + (cur / 10);
		if (!visited[next]) {
			visited[next] = true;
			q.push({ next, op + "R" });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int cur, dest;
		cin >> cur >> dest;
		string ans = bfs(cur, dest);
		cout << ans << "\n";
	}

	return 0;
}
