#include <iostream>

using namespace std;

int N, M;
int from, to;
int res = 0;
int arr[100002];
int sum[100002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	arr[0] = 0;
	sum[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to;
		cout << sum[to] - sum[from - 1] << '\n';
	}
}