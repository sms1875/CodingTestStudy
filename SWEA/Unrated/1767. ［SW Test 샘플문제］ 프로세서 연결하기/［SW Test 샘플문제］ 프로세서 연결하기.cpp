#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> arr;
vector<vector<bool>> visited;
vector<pair<int, int>> cores;

int res;
int maxConnected;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };


void dfs(int cnt, int len, int connected) {
    // 최소 길이 갱신
    if (maxConnected == connected) {
        res = min(res, len);
    }
    else if (maxConnected < connected) {
        maxConnected = connected;
        res = len;
    }

    if (cnt >= cores.size()) {
        return;
    }   

    if (connected + (cores.size() - cnt) < maxConnected) {
        return;
    }

    pair<int, int> cur = cores[cnt];

    // 모서리에 위치한 코어는 이미 연결된 것으로 간주하고 다음 코어 탐색
    if (cur.first == 0 || cur.second == 0 || cur.first == N - 1 || cur.second == N - 1) {
        dfs(cnt + 1, len, connected + 1);
        return;
    }

    // 4방향으로 시도
    for (int i = 0; i < 4; i++) {
        bool isCross = false;
        int ny = cur.first;
        int nx = cur.second;
        int nl = 0;
        vector<pair<int, int>> path;  // 전선 경로 저장

        // 전선 설치 시도
        while (true) {
            ny += dy[i];
            nx += dx[i];

            // 범위를 벗어나면 전원이 연결된 것
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) {
                break;
            }

            // 다른 전선이나 코어와 교차하는 경우
            if (visited[ny][nx]) {
                isCross = true;
                break;
            }

            // 전선 설치 가능 경로로 간주
            path.push_back({ ny, nx });
            nl++;
        }

        // 교차 발생 시 다음 방향으로 시도
        if (isCross) {
            continue;
        }

        // 전선 설치
        for (auto& p : path) {
            visited[p.first][p.second] = true;
        }

        // 다음 코어 탐색
        dfs(cnt + 1, len + nl, connected + 1);

        // 전선 원상복구
        for (auto& p : path) {
            visited[p.first][p.second] = false;
        }
    }

    // 해당 코어를 연결하지 않고 넘어가는 경우
    dfs(cnt + 1, len, connected);
}


int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;

        arr.clear(); arr.resize(N, vector<int>(N));
        visited.clear(); visited.resize(N, vector<bool>(N, false));
        cores.clear();
        res = 21e8; maxConnected = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
                // 코어 좌표 저장
                if (arr[i][j] == 1) {
                    cores.push_back({ i, j });
                    visited[i][j] = true;
                }
            }
        }

        dfs(0, 0, 0);

        cout << "#" << tc << " " << res << "\n";
    }
}
