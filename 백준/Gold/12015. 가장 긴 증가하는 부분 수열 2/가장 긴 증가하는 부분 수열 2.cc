#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 이진 탐색 함수: 정렬된 배열에서 num 이상의 첫 번째 위치를 찾음
// lower_bound 함수를 통해서 사용 가능
int binary_search(vector<int>& lis, int num) {
	int low = 0, high = lis.size();

	while (low < high) {
		int mid = low + (high - low) / 2;
		if (lis[mid] < num) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	return low;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> arr(N);  // 입력된 수열
	vector<int> lis;  // LIS를 저장할 벡터
	vector<int> pos(N);  // 각 숫자가 LIS에서 들어간 위치를 기록할 배열
	vector<int> trace(N, -1);  // 이전 위치 추적을 위한 배열

	// 입력 받기
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// LIS 구하기
	for (int i = 0; i < N; i++) {
		int num = arr[i];
		int pos_in_lis = binary_search(lis, num);  // 이진 탐색을 통해 LIS에서 들어갈 위치를 찾음
		

		if (pos_in_lis == lis.size()) {
			lis.push_back(num);  // 새로운 숫자를 LIS의 끝에 추가
		}
		else {
			lis[pos_in_lis] = num;  // 해당 위치의 값을 갱신
		}

		pos[i] = pos_in_lis;  // 해당 숫자가 들어간 위치 기록

		// trace 배열로 이전 요소 추적
		if (pos_in_lis > 0) {
			trace[i] = pos_in_lis - 1;
		}
	}

	// LIS 복원하기
	vector<int> actual_lis(lis.size());
	int current_pos = lis.size() - 1;
	for (int i = N - 1; i >= 0; i--) {
		if (pos[i] == current_pos) {
			actual_lis[current_pos] = arr[i];
			current_pos--;
		}
	}

	cout << lis.size();

	return 0;
}
