#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

struct Stair {
	int x;   
	int y; 
	int len; 
};


struct People {
	int x;     
	int y;     
	int s1_len;  
	int s2_len; 
};

int n;              
vector<Stair> stairs;  
vector<People> people;
int minTime; 

void init() {
	minTime = INT_MAX;
	stairs.clear();
	people.clear();
}

void input() {
	// 방의 정보를 입력받고, 사람과 계단의 위치를 저장
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			int num;
			cin >> num;

			if (num > 1) {
				stairs.push_back(Stair{ x, y, num });
			}
			else if (num == 1) {
				people.push_back(People{ x, y });
			}
		}
	}

	// 사람과 계단 간의 거리 계산
	for (int i = 0; i < people.size(); i++) {
		people[i].s1_len = abs(people[i].x - stairs[0].x) + abs(people[i].y - stairs[0].y);
		people[i].s2_len = abs(people[i].x - stairs[1].x) + abs(people[i].y - stairs[1].y);
	}
}

int calculateTime(const vector<int>& stair_choice) {
	// 사람들이 계단에 도착하는 시간 추가
	vector<int> times[2]; 
	for (int i = 0; i < people.size(); ++i) {
		if (stair_choice[i] == 0) {
			times[0].push_back(people[i].s1_len);
		}
		else {
			times[1].push_back(people[i].s2_len);
		}
	}

	int max_time = 0;
	for (int i = 0; i < 2; ++i) {
		if (times[i].empty()) continue; // 계단에 가는 사람이 없으면 패스
		sort(times[i].begin(), times[i].end()); // 계단에 도착하는 시간이 짧은 순으로 정렬
		
		// 대기 인원이 계단에서 내려가는 시간을 처리
		queue<int> q;
		for (int t : times[i]) {
			while (!q.empty() && q.front() <= t) q.pop(); // 시간 지나간 인원 제거
			if (q.size() < 3) {
				q.push(t + stairs[i].len + 1); // 계단에 대기
			}
			else {
				int wait_time = q.front(); // 대기 중인 사람의 시간
				q.pop();
				q.push(wait_time + stairs[i].len); // 계단을 내려가고 나서 다음 사람 대기
			}
		}
		// 큐에 남아 있는 사람들의 완료 시간을 계산
		while (!q.empty()) {
			max_time = max(max_time, q.front());
			q.pop();
		}
	}
	return max_time;
}

int solve() {
	int num_people = people.size(); 
	int total_combinations = (1 << num_people); // 가능한 모든 계단 선택 조합의 수

	for (int mask = 0; mask < total_combinations; ++mask) {
		// 비트마스킹을 통해 계단 선택 조합 생성
		vector<int> stair_choice(num_people);
		for (int i = 0; i < num_people; ++i) {
			stair_choice[i] = (mask & (1 << i)) ? 1 : 0;
		}

		minTime = min(minTime, calculateTime(stair_choice));
	}

	return minTime;
}

int main(int argc, char** argv) {
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		init();    
		input();   
		int result = solve(); 
		cout << "#" << test_case << " " << result << "\n"; 
	}
	return 0;
}
