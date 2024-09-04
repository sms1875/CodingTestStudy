#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void solve(vector<vector<int>>& arr, const pair<int, int>& st) {
	int N = arr.size();
	int time = 0;
	int babySharkSize = 2;
	int eatCnt = 0;
	pair<int, int> curSharkPos = st;

	while (true) {
		pair<int, pair<int, int>> nextPos = { 0, {-1, -1} };

		vector<vector<bool>> visited(N, vector<bool>(N, false));
		queue<pair<int, pair<int, int>>> q;
		q.push({ 0,curSharkPos });
		visited[curSharkPos.first][curSharkPos.second] = true;

		vector<pair<int, pair<int, int>>> fish;  // 물고기 후보들 저장

		while (!q.empty()) {
			pair<int, pair<int, int>> cur = q.front();
			q.pop();

			int curDist = cur.first;
			int curY = cur.second.first;
			int curX = cur.second.second;

			// 물고기를 찾음
			if (arr[curY][curX] >= 1 && arr[curY][curX] < babySharkSize) {
				fish.push_back({ curDist, {curY, curX} });
			}

			for (int i = 0; i < 4; i++) {
				int ny = curY + dy[i];
				int nx = curX + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
				if (visited[ny][nx]) continue;
				if (arr[ny][nx] > babySharkSize) continue; // 상어보다 큰 물고기는 지나갈 수 없음
				visited[ny][nx] = true;
				q.push({ curDist + 1, {ny, nx} });
			}
		}

		// 후보들 중에서 가장 가까운 물고기를 선택
		if (!fish.empty()) {
			// 거리, 위쪽, 왼쪽 순서로 정렬
			sort(fish.begin(), fish.end(), [](pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
				if (a.first == b.first) {
					if (a.second.first == b.second.first) {
						return a.second.second < b.second.second;  // x 좌표가 작은 것이 우선
					}
					return a.second.first < b.second.first;  // y 좌표가 작은 것이 우선
				}
				return a.first < b.first;  // 거리가 가까운 것이 우선
			});

			// 가장 가까운 물고기를 선택하여 이동
			nextPos = fish[0];
			curSharkPos = nextPos.second; // 상어 위치 이동
			time += nextPos.first;  // 이동한 거리 추가
			eatCnt++;  // 물고기를 먹음
			arr[curSharkPos.first][curSharkPos.second] = 0; // 물고기를 먹었으니 빈 칸으로 설정

			// 상어 크기 증가 체크
			if (eatCnt == babySharkSize) {
				babySharkSize++;
				eatCnt = 0;
			}
		}
		else {
			// 더 이상 먹을 물고기가 없는 경우
			break;
		}
	}

	cout << time;
}

int main() {
	int N;
	cin >> N;
	vector<vector<int>> arr(N, vector<int>(N));
	pair<int, int> babySharkPos;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				babySharkPos.first = i;
				babySharkPos.second = j;
				arr[i][j] = 0;  
			}
		}
	}

	solve(arr, babySharkPos);

	return 0;
}
