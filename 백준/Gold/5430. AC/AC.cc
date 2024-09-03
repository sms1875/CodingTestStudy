#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// 배열 문자열을 파싱하여 벡터로 변환하는 함수
vector<int> parseArrayString(const string& arrStr) {
	vector<int> v;

	// 배열 문자열에서 대괄호 제거 후 내부의 숫자들을 추출
	if (arrStr.length() > 2) {  // 빈 배열이 아닌 경우에만 파싱
		string innerArrayStr = arrStr.substr(1, arrStr.length() - 2);
		istringstream sstream(innerArrayStr);  // 문자열을 스트림으로 변환
		string token;

		// 쉼표를 기준으로 문자열을 나누어 숫자로 변환 후 벡터에 추가
		while (getline(sstream, token, ',')) {
			v.push_back(stoi(token));  // 문자열을 정수로 변환하여 벡터에 추가
		}
	}

	return v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string ops;
		int len;
		string arrStr;

		cin >> ops >> len >> arrStr;  // 함수 문자열, 배열 길이, 배열 문자열 입력

		vector<int> arr = parseArrayString(arrStr);
		bool isReverse = false;
		int front = 0, back = 0;
		bool isError = false;
		for (auto op : ops) {
			if (op == 'R') {
				isReverse = !isReverse;  // 뒤집기 연산 시 플래그만 변경
			}
			else if (op == 'D') {
				if (front + back >= arr.size()) {
					cout << "error\n";
					isError = true;
					break;
				}
				if (isReverse) {
					back++;  // 뒤집어진 상태에서는 뒤에서 제거
				}
				else {
					front++;  // 일반 상태에서는 앞에서 제거
				}
			}
		}

		if (isError) {
			continue;
		}

		// 결과 출력
		cout << '[';
		if (isReverse) {
			for (int i = arr.size() - back - 1; i >= front; --i) {
				cout << arr[i];
				if (i != front) cout << ',';
			}
		}
		else {
			for (int i = front; i < arr.size() - back; ++i) {
				cout << arr[i];
				if (i != arr.size() - back - 1) cout << ',';
			}
		}
		cout << "]\n";
	}

	return 0;
}
