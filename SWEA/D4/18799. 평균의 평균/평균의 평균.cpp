#include <iostream>
#include <vector>

using namespace std;

int arr[9];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		double result = 0.0;
		int n;

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		int subsetCount = 1 << n; // 부분집합 개수

		for (int mask = 1; mask < subsetCount; ++mask) { // 공집합 제외
			double subsetSum = 0.0;
			int subsetSize = 0;

			for (int i = 0; i < n; ++i) {
				if (mask & (1 << i)) {
					subsetSum += arr[i];
					subsetSize++;
				}
			}

			double subsetAverage = subsetSum / subsetSize;
			result += subsetAverage;
		}

		result /= subsetCount - 1; // 공집합 제외

		cout << fixed;
		cout.precision(18);
		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}