#include <iostream>
using namespace std;

int n;
int result = 0;

void solve(int row, int col_mask, int diag1_mask, int diag2_mask) {
	if (row == n) {
		result++;
		return;
	}

	// 가능한 열 위치를 비트마스크로 표현
	int available = ((1 << n) - 1) & ~(col_mask | diag1_mask | diag2_mask);

	while (available) {
		int bit = available & -available;  // 가장 오른쪽의 1비트 추출
		available -= bit;  // 현재 선택한 열을 제거
		solve(row + 1, col_mask | bit, (diag1_mask | bit) << 1, (diag2_mask | bit) >> 1);
	}
}

int main() {
	cin >> n;
	solve(0, 0, 0, 0);
	cout << result << endl;
	return 0;
}
