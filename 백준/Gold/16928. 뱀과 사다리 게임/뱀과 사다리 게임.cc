#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <algorithm>

using namespace std;

int ans=21e8;

void solve(int cur, int cnt, unordered_map<int, int> ladders, unordered_map<int, int> snakes) {
	if (cur >= 100) {
		ans = min(ans, cnt);
		return;
	}

	if (cnt > ans) {
		return;
	}	

	//사다리
	for (int i = 1; i <= 6; i++)
	{
		if (ladders[cur + i])
			solve(ladders[cur + i], cnt + 1, ladders, snakes);
	}

	//사다리, 뱀이 없는 가장큰수
	for (int i = 6; i > 0; i--)
	{
		if (ladders[cur + i] == 0 && snakes[cur + i] == 0) {
			solve(cur + i, cnt + 1, ladders, snakes);
			break;
		}
	}

	//뱀
	//가지치기 조건을위해 가장마지막에서함
	for (int i = 1; i <= 6; i++)
	{
		if (snakes[cur + i])
			solve(snakes[cur + i], cnt + 1, ladders, snakes);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	unordered_map<int, int> ladders;
	unordered_map<int, int> snakes;
	for (int i = 0; i < N; i++)
	{
		int from, to;
		cin >> from >> to;
		ladders[from] = to;
	}
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		snakes[from] = to;
	}

	solve(1, 0, ladders, snakes);
	cout << ans;

	return 0;
}
