#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct BC {
	int x, y, c, p; // 위치 (x, y), 충전 범위 c, 성능 p
};

vector<int> movements_A, movements_B;
vector<BC> batteryChargers;
vector<vector<int>> map;
int M, A;

//(0: 이동 안함, 1: 상, 2: 우, 3: 하, 4: 좌)
int dx[] = { 0, 0, 1, 0, -1 };
int dy[] = { 0, -1, 0, 1, 0 };

void initialize_map() {
	// 맵 초기화
	map.clear();
	map.resize(11, vector<int>(11, 0));

	// 각 BC의 범위를 비트마스크로 맵에 저장
	for (int i = 0; i < A; ++i) {
		int x = batteryChargers[i].x;
		int y = batteryChargers[i].y;
		int c = batteryChargers[i].c;
		int bitmask = (1 << i); // BC i의 비트마스크

		for (int dx = -c; dx <= c; ++dx) {
			for (int dy = -c; dy <= c; ++dy) {
				int nx = x + dx;
				int ny = y + dy;
				if (nx >= 1 && nx <= 10 && ny >= 1 && ny <= 10) {
					if (abs(x - nx) + abs(y - ny) <= c) {
						map[nx][ny] |= bitmask; // 비트마스크 추가
					}
				}
			}
		}
	}
}

vector<int> get_charging_options(int x, int y) {
	vector<int> options;
	int bitmask = map[x][y];

	for (int i = 0; i < batteryChargers.size(); ++i) {
		if (bitmask & (1 << i)) {
			options.push_back(i);
		}
	}

	return options;
}

int simulate() {
	// 사용자 초기 위치
	pair<int, int> pos_A = { 1, 1 };
	pair<int, int> pos_B = { 10, 10 };

	int total_charge_A = 0;
	int total_charge_B = 0;

	// 매초마다 위치 갱신 및 충전 계산
	for (int t = 0; t <= M; t++) {  // 0초부터 M초까지
		// 현재 위치에서 가능한 충전기 리스트 구하기
		vector<int> options_A = get_charging_options(pos_A.first, pos_A.second);
		vector<int> options_B = get_charging_options(pos_B.first, pos_B.second);

		int max_charge = 0;

		if (!options_A.empty() && !options_B.empty()) {  // 두 사용자 모두 충전기가 있을 때
			for (int i : options_A) {
				for (int j : options_B) {
					int charge;
					if (i == j) {  // 같은 충전기일 경우
						charge = batteryChargers[i].p;
					}
					else {  // 다른 충전기를 선택한 경우 각각 충전 가능
						charge = batteryChargers[i].p + batteryChargers[j].p;
					}
					max_charge = max(max_charge, charge);  // 최댓값 갱신
				}
			}
		}
		else if (!options_A.empty()) {  // 사용자 A만 충전 가능한 경우
			int best_A = 0;
			for (int i : options_A) {
				best_A = max(best_A, batteryChargers[i].p);
			}
			max_charge = best_A;
		}
		else if (!options_B.empty()) {  // 사용자 B만 충전 가능한 경우
			int best_B = 0;
			for (int i : options_B) {
				best_B = max(best_B, batteryChargers[i].p);
			}
			max_charge = best_B;
		}

		total_charge_A += max_charge;

		// 다음 초로 이동 (0초는 이동하지 않음)
		if (t < M) {
			pos_A.first += dx[movements_A[t]];
			pos_A.second += dy[movements_A[t]];
			pos_B.first += dx[movements_B[t]];
			pos_B.second += dy[movements_B[t]];
		}
	}

	return total_charge_A;
}

int main() {
	int T;  // 테스트 케이스 개수
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> M >> A;

		movements_A.resize(M);
		movements_B.resize(M);
		for (int i = 0; i < M; i++) cin >> movements_A[i];
		for (int i = 0; i < M; i++) cin >> movements_B[i];

		batteryChargers.resize(A);
		for (int i = 0; i < A; i++) {
			cin >> batteryChargers[i].x >> batteryChargers[i].y >> batteryChargers[i].c >> batteryChargers[i].p;
		}

		// 맵 초기화 및 비트마스크 설정
		initialize_map();

		// 시뮬레이션 수행
		int result = simulate();

		// 결과 출력
		cout << "#" << t << " " << result << "\n";
	}

	return 0;
}
