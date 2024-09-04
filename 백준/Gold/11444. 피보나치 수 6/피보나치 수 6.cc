#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;  // 피보나치 수를 나눌 큰 소수

// 2x2 행렬의 곱셈을 수행하는 함수
vector<vector<long long>> matrixMultiply(const vector<vector<long long>>& a, const vector<vector<long long>>& b) {
	vector<vector<long long>> result(2, vector<long long>(2, 0));  // 결과 행렬을 초기화
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;  // 행렬 곱셈 후 MOD 연산
			}
		}
	}
	return result;
}

// 2x2 행렬을 n번 곱하는 함수
vector<vector<long long>> matrixPower(vector<vector<long long>> base, long long exp) {
	vector<vector<long long>> result = { {1, 0}, {0, 1} };  // 항등 행렬로 초기화
	while (exp > 0) {
		if (exp % 2 == 1) {  // 지수가 홀수이면
			result = matrixMultiply(result, base);  // 결과에 현재 행렬을 곱함
		}
		base = matrixMultiply(base, base);  // 행렬을 제곱
		exp /= 2;  // 지수를 반으로 줄임
	}
	return result;
}

// n번째 피보나치 수를 계산하는 함수
long long fibonacci(long long n) {
	if (n == 0) return 0;
	vector<vector<long long>> base = { {1, 1}, {1, 0} };  // 피보나치 행렬 초기값 설정
	vector<vector<long long>> result = matrixPower(base, n - 1);  // 행렬 거듭제곱을 통해 피보나치 수 계산
	return result[0][0];  // 피보나치 수 반환
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long dist;
	cin >> dist;

	cout << fibonacci(dist) << "\n";  // n번째 피보나치 수 출력

	return 0;
}
