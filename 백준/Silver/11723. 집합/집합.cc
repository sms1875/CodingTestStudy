#include <iostream>
#include <string>

using namespace std;

int num = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string command;
		int tmp;
		cin >> command;
		if (command == "add") {
			cin >> tmp;
			num = num |(1 << (tmp - 1));
		}
		else if (command == "remove") {
			cin >> tmp;
			num = num & (~(1 << (tmp - 1)));
		}
		else if (command == "check") {
			cin >> tmp;
			cout << ((num >> (tmp - 1)) & 1) << "\n";
		}
		else if (command == "toggle") {
			cin >> tmp;
			num = num ^ (1 << (tmp - 1));
		}
		else if (command == "all") {
			num = 0xfffff;
		}
		else if (command == "empty") {
			num = 0;
		}
	}
	return 0;
}
