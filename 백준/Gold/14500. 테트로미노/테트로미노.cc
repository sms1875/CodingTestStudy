#include <iostream>
#include <queue>
#include<algorithm>

using namespace std;

int M, N;
int res = 0;
vector<vector<int>> arr;
vector<vector<bool>> visited;
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

void solve(pair<int, int> cur, int cnt, int sum) {
	if (cnt == 4) { 
		res = max(res, sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = cur.first + dy[i];
		int nx = cur.second + dx[i];
		if (ny <= 0 || nx <= 0 || ny > N || nx > M || visited[ny][nx]) continue;
		visited[ny][nx] = true;
		solve({ ny,nx }, cnt + 1, sum + arr[ny][nx]);
		visited[ny][nx] = false;
	}
}

int main() {
	cin >> N >> M;

	arr.resize(N + 2, vector<int>(M + 2, 0));
	visited.resize(N + 2, vector<bool>(M + 2, false));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			visited[i][j] = true;
			solve({ i,j }, 1, arr[i][j]);
			visited[i][j] = false;

			int cross = arr[i][j] + arr[i - 1][j] + arr[i + 1][j] + arr[i][j - 1] + arr[i][j + 1];
			cross -= min(min(arr[i - 1][j], arr[i + 1][j]), min(arr[i][j - 1], arr[i][j + 1]));//가장작은값
			res = max(res, cross);
		}
	}
	cout << res;
}