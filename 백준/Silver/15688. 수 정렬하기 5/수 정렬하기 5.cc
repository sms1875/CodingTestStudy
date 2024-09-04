#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	map<int, int> map;
	while (N--) {
		int num;
		cin >> num;
		map[num]++;
	}

	for (auto i : map)
	{
		while (i.second--) {
			cout << i.first << "\n";
		}
	}

}