#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;  // n: 바구니의 개수, m: 명령의 개수

    vector<int> baskets(n);

    // 바구니 초기화
    for (int i = 0; i < n; ++i) {
        baskets[i] = i + 1;
    }

    // m개의 명령 처리
    for (int i = 0; i < m; ++i) {
        int begin, end, mid;
        cin >> begin >> end >> mid;
        begin--;  // 인덱스는 0부터 시작하므로 1 감소
        end--;   // 인덱스는 0부터 시작하므로 1 감소
        mid--;   // 인덱스는 0부터 시작하므로 1 감소

        // 부분 배열 회전
        rotate(baskets.begin() + begin, baskets.begin() + mid, baskets.begin() + end + 1);
    }

    // 최종 배열 출력
    for (int i = 0; i < n; ++i) {
        cout << baskets[i] << " ";
    }
    cout << endl;

    return 0;
}
