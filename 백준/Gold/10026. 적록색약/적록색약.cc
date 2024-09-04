#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, -1, 0, 1 };

void bfs(int y, int x, vector<vector<bool>>& visited, const vector<vector<char>>& arr, bool colorblind) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;
	char currentColor = arr[y][x];

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= arr.size() || nx >= arr.size()) continue;
			if (visited[ny][nx]) continue;

			if (colorblind) {
				// 적록색약의 경우 'R'과 'G'를 같은 색상으로 간주
				if ((currentColor == 'R' || currentColor == 'G') && (arr[ny][nx] == 'R' || arr[ny][nx] == 'G')) {
					visited[ny][nx] = true;
					q.push({ ny, nx });
				}
				else if (currentColor == arr[ny][nx]) {
					visited[ny][nx] = true;
					q.push({ ny, nx });
				}
			}
			else {
				if (currentColor == arr[ny][nx]) {
					visited[ny][nx] = true;
					q.push({ ny, nx });
				}
			}
		}
	}
}

void solve(const vector<vector<char>>& arr) {
	int cntNormal = 0;
	int cntColorblind = 0;

	vector<vector<bool>> visitedNormal(arr.size(), vector<bool>(arr.size(), false));
	vector<vector<bool>> visitedColorblind(arr.size(), vector<bool>(arr.size(), false));

	// 일반 사람의 경우
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {
			if (!visitedNormal[i][j]) {
				bfs(i, j, visitedNormal, arr, false);
				cntNormal++;
			}
		}
	}

	// 적록색약의 경우
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {
			if (!visitedColorblind[i][j]) {
				bfs(i, j, visitedColorblind, arr, true);
				cntColorblind++;
			}
		}
	}

	cout << cntNormal << " " << cntColorblind << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<vector<char>> arr(N, vector<char>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	solve(arr);

	return 0;
}
