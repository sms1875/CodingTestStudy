#include <vector>

using namespace std;

int union_find[201];

int find(int tar)
{
	if (tar == union_find[tar])
		return tar;

	int ret = find(union_find[tar]);
	union_find[tar] = ret;
	return ret;
}

void setUnion(int a, int b)
{
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2)
		return;

	union_find[t2] = t1;
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	//초기화
	for (int i = 0; i < n; i++) {
		union_find[i] = i;
	}

	//union-find 설정
	for (int computer = 0; computer < n; computer++)
	{
		for (int connect = 0; connect < n; connect++)
		{
			if (computers[computer][connect]) {
				setUnion(computer, connect);
			}
		}
	}

	// root node 확인
	vector<bool> visited(n, false);

	for (int i = 0; i < n; i++) {
		int root = find(i);
		if (!visited[root]) {
			answer++;
			visited[root] = true;
		}
	}

	return answer;
}