#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	multiset<int> set;
	while (M + N--) {
		int num;
		cin >> num;
		set.insert(num);
	}

	for (auto num : set)
	{
		cout << num << " ";
	}
}