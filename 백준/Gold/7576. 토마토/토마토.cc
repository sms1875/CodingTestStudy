#include <iostream>
#include <queue>

using namespace std;

int M, N;
vector<vector<int>> arr;
vector<pair<int, int>> st;
int cnt = 0;

void solve() {
	int dy[4] = { 0,1,0,-1 };
	int dx[4] = { 1,0,-1,0 };
	int minV = 0;

	if (cnt == 0) {
		cout << 0;
		return;
	}

	queue<pair<int, int>> q;
	for (const auto& s : st) {
		q.push(s);
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (arr[ny][nx] != 0) continue;
			arr[ny][nx] = arr[cur.first][cur.second] + 1;
			cnt--;
			q.push({ ny, nx });
			minV = max(minV, arr[ny][nx]);
		}
	}
	cout << (cnt == 0 ? minV - 1 : -1);
}

int main() {
	cin >> M >> N;

	arr.resize(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0) 
				cnt++;
			else if (arr[i][j] == 1) 
				st.push_back({ i,j });
		}
	}
	solve();
}