#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, string> union_find;
unordered_map<string, int> group_size;

string find(string tar)
{
	// 현재 노드가 루트가 아니면, 루트를 찾을 때까지 재귀적으로 호출
	if (tar != union_find[tar]) {
		// 경로 압축: 루트를 찾고, 현재 노드의 상위 노드를 루트로 갱신
		union_find[tar] = find(union_find[tar]);
	}
	return union_find[tar];
}

void setUnion(string a, string b)
{
	string t1 = find(a);
	string t2 = find(b);

	if (t1 != t2)
	{
		// Union by Size
		if (group_size[t1] < group_size[t2]) {
			swap(t1, t2); // t1이 항상 큰 그룹이 되도록 보장
		}
		union_find[t2] = t1;
		group_size[t1] += group_size[t2];
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		// 초기화
		union_find.clear();
		group_size.clear();

		while (n--) {
			string parent, child;
			cin >> parent >> child;

			// 처음 입력된 parent
			if (union_find.find(parent) == union_find.end()) {
				union_find[parent] = parent;
				group_size[parent] = 1;
			}

			// 처음 입력된 child
			if (union_find.find(child) == union_find.end()) {
				union_find[child] = child;
				group_size[child] = 1;
			}

			setUnion(parent, child);

			// 합친 후 부모의 그룹 크기를 출력
			cout << group_size[find(parent)] << '\n';
		}
	}
	return 0;
}
