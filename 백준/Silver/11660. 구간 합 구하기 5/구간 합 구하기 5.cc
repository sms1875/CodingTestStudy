#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, M;  
	cin >> N >> M;
	vector<vector<int>> arr(N + 2,vector<int>(N + 2, 0));
	vector<vector<int>> sum(N + 2, vector<int>(N + 2, 0));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
			sum[i][j] = arr[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}

	for (int i = 0; i < M; i++)
	{
		int fromX, fromY, toX, toY;
		cin >> fromX >> fromY >> toX >> toY;
		cout << sum[toX][toY] - sum[fromX - 1][toY] - sum[toX][fromY - 1] + sum[fromX - 1][fromY - 1] << "\n";
    }
	
	return 0;
}
