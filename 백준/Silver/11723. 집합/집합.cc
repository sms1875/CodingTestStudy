#include <iostream>
#include <string>

using namespace std;

int bitmask = 0; // 비트 연산을 위한 변수

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		string command;
		int num;
		cin >> command;

		if (command == "add") {
			cin >> num;
			int bit_to_set = (1 << (num - 1)); // num 번째 비트를 1로 설정하기 위한 비트 마스크 계산
			bitmask = bitmask | bit_to_set; // 비트 연산: OR 연산을 통해 num 번째 비트를 1로 설정
		}
		else if (command == "remove") {
			cin >> num;
			int bit_to_clear = (1 << (num - 1)); // num 번째 비트를 0으로 설정하기 위한 비트 마스크 계산
			bitmask = bitmask & (~bit_to_clear); // 비트 연산: AND 연산과 NOT 연산을 통해 num 번째 비트를 0으로 설정
		}
		else if (command == "check") {
			cin >> num;
			int bit_to_check = (1 << (num - 1)); // num 번째 비트를 확인하기 위한 비트 마스크 계산
			int check_result = (bitmask & bit_to_check); // 비트 연산: AND 연산을 통해 num 번째 비트가 1인지 확인
			int is_set = (check_result >> (num - 1)); // 비트 연산: 오른쪽으로 쉬프트하여 비트 값 추출 (0 또는 1)
			cout << is_set << "\n"; // 비트 값 출력 (1 또는 0)
		}
		else if (command == "toggle") {
			cin >> num;
			int bit_to_toggle = (1 << (num - 1)); // num 번째 비트를 반전시키기 위한 비트 마스크 계산
			bitmask = bitmask ^ bit_to_toggle; // 비트 연산: XOR 연산을 통해 num 번째 비트를 반전
		}
		else if (command == "all") {
			bitmask = 0xFFFFF; // 모든 비트를 1로 설정 (20 비트의 모든 비트를 1로 설정)
		}
		else if (command == "empty") {
			bitmask = 0; // 모든 비트를 0으로 설정
		}
	}
	return 0;
}
