#include<iostream>
#include<cstring>
#include <algorithm>
#include<vector>
using namespace std;

int arr[21][21];
int N;
int res;
int st_x, st_y;
bool visited[101];

int dx[4] = { 1 , -1, -1, 1 };
int dy[4] = { 1, 1, -1, -1 };


void dfs(int y, int x, int dir) {

	if (dir == 4) { 
		//도착 확인
		if (st_x == x && st_y == y) {
			int sum = 0;
			for (int i = 0; i < 101; i++)
			{
				if (visited[i]) {
					sum++;
				}
			}
			res = max(sum, res);
		}
		return; 
	}

	for (int i = 1; i < N; i++)
	{
		int nx = dx[dir]*i + x;
		int ny = dy[dir]*i + y;

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
	
		// 사이 경로 방문 처리
		for (int j = 1; j <= i; j++)
		{
			int nx2 = dx[dir] * j + x;
			int ny2 = dy[dir] * j + y;
			// 경로 사이에 중복되는 디저트 종류 존재
			if (visited[arr[ny2][nx2]]) {
				for (int k = 0; k < j; k++)
				{
					int nx3 = dx[dir] * k + x;
					int ny3 = dy[dir] * k + y;
					visited[arr[ny3][nx3]] = false;
				}
				return;
			}
			visited[arr[ny2][nx2]] = true;
		}

		dfs(ny, nx, dir + 1);

		for (int j = 1; j <= i; j++)
		{
			int nx2 = dx[dir] * j + x;
			int ny2 = dy[dir] * j + y;
			visited[arr[ny2][nx2]] = false;
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		res = -1;
		memset(arr, 0, sizeof(arr));

		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				memset(visited, 0, sizeof(visited));
				st_y = i; st_x = j; 
				dfs(st_y, st_x, 0);
			}
		}


		cout << "#" << test_case << " "<< res << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}