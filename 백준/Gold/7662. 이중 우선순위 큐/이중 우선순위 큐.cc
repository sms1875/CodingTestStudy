#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		unordered_map<int, int> map;
		priority_queue<int> maxpq; // 최대 힙
		priority_queue<int, vector<int>, greater<int>> minpq; // 최소 힙
		int Q;
		cin >> Q;
		int numCnt = 0;

		while (Q--) {
			char op;
			cin >> op;
			int n;
			cin >> n;
			if (op == 'I') {
				maxpq.push(n);
				minpq.push(n);
				map[n]++; // 해당 숫자의 삽입 횟수 증가
				numCnt++;
			}
			else {
				if (numCnt == 0) continue; // 유효한 숫자가 없는 경우 무시
				numCnt--;

				if (n == 1) { // 최대값 삭제
					if (maxpq.empty()) continue;
					while (map[maxpq.top()] == 0) {
						maxpq.pop();
					}
					map[maxpq.top()]--;
					maxpq.pop();
				}
				else { // 최소값 삭제
					if (minpq.empty()) continue;
					while (map[minpq.top()] == 0) {
						minpq.pop();
					}
					map[minpq.top()]--;
					minpq.pop();
				}
			}
		}

		// 남아있는 유효한 최댓값과 최솟값을 확인
		while (!maxpq.empty() && map[maxpq.top()] == 0) {
			maxpq.pop();
		}
		while (!minpq.empty() && map[minpq.top()] == 0) {
			minpq.pop();
		}

		if (numCnt == 0 || maxpq.empty() || minpq.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << maxpq.top() << " " << minpq.top() << "\n";
		}
	}

	return 0;
}
