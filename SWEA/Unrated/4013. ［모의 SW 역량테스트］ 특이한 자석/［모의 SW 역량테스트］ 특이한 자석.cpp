#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[4][8];
int K;
vector<pair<int, int>> changes;
int res;

// 왼쪽 회전 함수
void leftRotate(int gear, int k) {
	int temp[8];
	//회전
	for (int i = 0; i < 8; ++i) {
		temp[(i - k + 8) % 8] = arr[gear][i];
	}
	//적용
	for (int i = 0; i < 8; ++i) {
		arr[gear][i] = temp[i];
	}
}

// 오른쪽 회전 함수
void rightRotate(int gear, int k) {
	int temp[8];
	//회전
	for (int i = 0; i < 8; ++i) {
		temp[(i + k) % 8] = arr[gear][i];
	}
	//적용
	for (int i = 0; i < 8; ++i) {
		arr[gear][i] = temp[i];
	}
}

void solve() {

	for (int i = 0; i < changes.size(); i++)
	{
		int gear = changes[i].first;
		int dir = changes[i].second;
		vector<pair<int, int>> changeGears;//바꿀기어 넣어둘곳
		changeGears.push_back({ gear,dir });//처음기어

		// 기어 오른쪽확인
		for (int rightGear = gear; rightGear < 3; rightGear++)
		{
			if (arr[rightGear][2] != arr[rightGear + 1][6]) {
				dir = (dir == 1 ? -1 : 1);
				changeGears.push_back({ rightGear + 1, dir });
			}
			else break;
		}

		dir = changes[i].second;//처음기어 방향 복구

		// 기어 왼쪽확인
		for (int leftGear = gear; leftGear > 0; leftGear--)
		{
			if (arr[leftGear][6] != arr[leftGear - 1][2]) {
				dir = (dir == 1 ? -1 : 1);
				changeGears.push_back({ leftGear - 1, dir });
			}
			else break;
		}

		//기어 회전
		for (int j = 0; j < changeGears.size(); j++)
		{
			int changeGearNum = changeGears[j].first;
			int changeDir = changeGears[j].second;
			(changeDir > 0) ? rightRotate(changeGearNum, changeDir) : leftRotate(changeGearNum, -changeDir);
		}
	}

	for (int j = 0; j < 4; j++)
	{
		res += (arr[j][0] << (j));
	}
}

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		changes.clear();
		res = 0;
		cin >> K;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < K; i++)
		{
			int a, b;
			cin >> a >> b;
			changes.push_back({ a - 1,b });
		}

		solve();

		cout << "#" << tc << " " << res << "\n";
	}
	return 0;
}
