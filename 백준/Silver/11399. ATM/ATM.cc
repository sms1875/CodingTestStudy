#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	int ans = 0;
	int N;
	cin >> N;
	vector<int> time(N);
	for (int i = 0; i < N; i++)
	{
		cin >> time[i];
	}
	sort(time.begin(), time.end());
	for (int i = N-1; i >= 0; i--)
	{
		ans += time[i] * (N-i);
	}
	cout << ans;
	return 0;
}