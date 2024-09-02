#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>


using namespace std;

int res = 21e8;

void solve(int num, int opCnt) {
	if (num <= 0) return;
	if (num == 1) {
		res = min(opCnt, res);
		return;
	}
	if (opCnt >= res) return;

	if (num % 3 == 0) solve(num / 3, opCnt + 1);
	if (num % 2 == 0) solve(num / 2, opCnt + 1);
	solve(num - 1, opCnt + 1);
}

int main() {
	int num;
	cin >> num;
	solve(num, 0);
	cout << res;
	return 0;
}