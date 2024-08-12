#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>

using namespace std;

int arr[101][101];

int answer = 21e8;
int firstGroupCnt = 0;

void dfs(int start, int n)
{
	firstGroupCnt = 0;
	bool visited[101] = { false };
	stack<int> s;
	s.push(start);
	while (!s.empty())
	{
		int current = s.top();
		s.pop();

		if (visited[current])
			continue;
		visited[current] = true;
		firstGroupCnt++;
		for (int next = 0; next < n; next++)
		{
			if (arr[current][next] == 1 && !visited[next])
			{
				s.push(next);
			}
		}
	}

	// 두 번째 그룹은 전체 노드 수에서 첫 번째 그룹의 노드 수를 뺀 값
	int SecondGroupCount = n - firstGroupCnt;

	answer = min(answer, abs(firstGroupCnt - SecondGroupCount));
}

int solution(int n, vector<vector<int>> wires)
{

	// 노드 생성
	for (const auto &wire : wires)
	{
		arr[wire[0] - 1][wire[1] - 1] = 1;
		arr[wire[1] - 1][wire[0] - 1] = 1;
	}

	// 와이어 삭제 후 송전탑 개수 계산
	for (int from = 0; from < n; ++from)
	{
		for (int to = from + 1; to < n; ++to)
		{
			if (arr[from][to] == 1)
			{
				// 연결된 와이어 제거
				arr[from][to] = 0;
				arr[to][from] = 0;

				// 첫 번째 그룹 탐색
				dfs(from, n);

				// 제거했던 와이어 다시 복구
				arr[from][to] = 1;
				arr[to][from] = 1;
			}
		}
	}

	return answer;
}
