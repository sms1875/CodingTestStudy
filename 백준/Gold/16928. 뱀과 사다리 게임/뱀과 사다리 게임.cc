#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

int bfs(int start, const unordered_map<int, int>& ladders, const unordered_map<int, int>& snakes) {
    vector<bool> visited(101, false); // 1~100까지 방문 여부 체크
    queue<pair<int, int>> q; // 현재 위치와 주사위 굴림 횟수를 저장
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        // 목표 지점에 도달했을 때
        if (cur >= 100) {
            return cnt;
        }

        for (int i = 1; i <= 6; i++) {
            int next = cur + i;
            if (next > 100) continue;

            // 사다리가 있는 경우
            if (ladders.count(next)) {
                next = ladders.at(next);
            }
            // 뱀이 있는 경우
            else if (snakes.count(next)) {
                next = snakes.at(next);
            }

            if (!visited[next]) {
                visited[next] = true;
                q.push({next, cnt + 1});
            }
        }
    }

    return -1; // 이론적으로 이 부분에 도달할 수 없음
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    unordered_map<int, int> ladders;
    unordered_map<int, int> snakes;

    for (int i = 0; i < N; i++) {
        int from, to;
        cin >> from >> to;
        ladders[from] = to;
    }

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        snakes[from] = to;
    }

    int result = bfs(1, ladders, snakes);
    cout << result << "\n";

    return 0;
}
