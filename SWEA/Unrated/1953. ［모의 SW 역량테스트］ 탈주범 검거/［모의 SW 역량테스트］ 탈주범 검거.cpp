#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


struct Point {
	int y, x;
	int day;
};

int N, M;
int R, C;
int L;
vector<vector<int>> arr;

int cnt = 0;

vector<pair<int, int>> pipeDir[8] = {
	{},
	{{0,-1},{-1,0},{0,1},{1,0}},
	{{-1,0},{1,0}},
	{{0,-1},{0,1}},
	{{-1,0},{0,1}},
	{{0,1},{1,0}},
	{{0,-1},{1,0}},
	{{0,-1},{-1,0}},
};

bool canMove(int curPipeType, int nextDir , int nextPipeType) {
	if (nextPipeType == 1)
		return true;
	else if (curPipeType == 1) {
		if (nextDir == 0)
			return (nextPipeType == 3 || nextPipeType == 4 || nextPipeType == 5) ? true : false;
		else if (nextDir == 1)
			return (nextPipeType == 2 || nextPipeType == 5 || nextPipeType == 6) ? true : false;
		else if (nextDir == 2)
			return (nextPipeType == 3 || nextPipeType == 6 || nextPipeType == 7) ? true : false;
		else
			return (nextPipeType == 2 || nextPipeType == 4 || nextPipeType == 7) ? true : false;
	}
	else if (curPipeType == 2) {
		if (nextDir == 0)
			return (nextPipeType == 2 || nextPipeType == 5 || nextPipeType == 6) ? true : false;
		else
			return (nextPipeType == 2 || nextPipeType == 4 || nextPipeType == 7) ? true : false;
	}
	else if (curPipeType == 3) {
		if (nextDir == 0)
			return (nextPipeType == 3 || nextPipeType == 4 || nextPipeType == 5) ? true : false;
		else
			return (nextPipeType == 3 || nextPipeType == 6 || nextPipeType == 7) ? true : false;
	}
	else if (curPipeType == 4) {
		if (nextDir == 0)
			return (nextPipeType == 2 || nextPipeType == 5 || nextPipeType == 6) ? true : false;
		else
			return (nextPipeType == 3 || nextPipeType == 6 || nextPipeType == 7) ? true : false;
	}
	else if (curPipeType == 5) {
		if (nextDir == 0)
			return (nextPipeType == 3 || nextPipeType == 6 || nextPipeType == 7) ? true : false;
		else
			return (nextPipeType == 2 || nextPipeType == 4 || nextPipeType == 7) ? true : false;
	}
	else if (curPipeType == 6) {
		if (nextDir == 0)
			return (nextPipeType == 3 || nextPipeType == 4 || nextPipeType == 5) ? true : false;
		else
			return (nextPipeType == 2 || nextPipeType == 4 || nextPipeType == 7) ? true : false;
	}
	else if (curPipeType == 7) {
		if (nextDir == 0)
			return (nextPipeType == 3 || nextPipeType == 4 || nextPipeType == 5) ? true : false;
		else
			return (nextPipeType == 2 || nextPipeType == 5 || nextPipeType == 6) ? true : false;
	}
}

void bfs() {
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	queue<Point> q;
	q.push({ R,C,1 });
	while (!q.empty()) {

		int cur_y = q.front().y;
		int cur_x = q.front().x;
		int cur_day = q.front().day;
		q.pop();

		if (cur_day > L) continue; //날짜가 넘으면 통과

		int curPipeType = arr[cur_y][cur_x];
		visited[cur_y][cur_x] = true; // 방문한 곳 기록

		for (int nextDir = 0; nextDir < pipeDir[curPipeType].size(); nextDir++)
		{
			int ny = pipeDir[curPipeType][nextDir].first + cur_y;
			int nx = pipeDir[curPipeType][nextDir].second + cur_x;

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue; // 범위 체크
			if (visited[ny][nx]) continue; // 방문했으면 통과
			if (arr[ny][nx] == 0) continue; // 파이프 없으면 통과 
			if (!canMove(curPipeType, nextDir, arr[ny][nx])) continue; // 다음 파이프에 갈 수 없으면 통과

			q.push({ ny,nx,cur_day + 1 });
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j]) cnt++; // 방문한 곳 카운트
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cnt = 0;
		cin >> N >> M;
		cin >> R >> C >> L;

		arr.clear(); arr.resize(N, vector<int>(M));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> arr[i][j];
			}
		}

		bfs();

		cout << "#" << tc << " " << cnt << "\n";
	}
	return 0;
}
