#include <iostream>
#include <queue>

using namespace std;

int N, M, H;
vector<vector<vector<int>>> arr; // [h][y][x]
vector<pair<int, pair<int, int>>> st;
int cnt = 0;

int dh[4] = { 1, -1 };
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void solve() {
	int minV = 0;

	if (cnt == 0) {
		cout << 0;
		return;
	}

	queue<pair<int, pair<int, int>>> q;
	for (const auto& s : st) {
		q.push(s);
	}

	while (!q.empty()) {
		pair<int, pair<int, int>> cur = q.front();
		q.pop();
		// 옆
		for (int i = 0; i < 4; i++)
		{
			int ny = cur.second.first + dy[i];
			int nx = cur.second.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (arr[cur.first][ny][nx] != 0) continue;
			arr[cur.first][ny][nx] = arr[cur.first][cur.second.first][cur.second.second] + 1;
			cnt--;
			q.push({ cur.first, {ny, nx } });
			minV = max(minV, arr[cur.first][ny][nx]);
		}
		// 위
		for (int i = 0; i < 2; i++)
		{
			int nh = cur.first + dh[i];
			if (nh < 0 || nh >= H) continue;
			if (arr[nh][cur.second.first][cur.second.second] != 0) continue;
			arr[nh][cur.second.first][cur.second.second] = arr[cur.first][cur.second.first][cur.second.second] + 1;
			cnt--;
			q.push({ nh, {cur.second.first, cur.second.second } });
			minV = max(minV, arr[nh][cur.second.first][cur.second.second]);
		}
	}
	cout << (cnt == 0 ? minV - 1 : -1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> M >> N >> H;

	arr.resize(H, vector<vector<int>>(N, vector<int>(M)));

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 0)
					cnt++;
				else if (arr[i][j][k] == 1)
					st.push_back({ i,{ j,k } });
			}
		}
	}
	solve();
}
