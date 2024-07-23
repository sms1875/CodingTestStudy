#include <iostream>
#include <vector>

using namespace std;



int main()
{
	int test_case;
	int T;	
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		long long result = 0;
		int max_price = 0;

		int N;
		cin >> N;

		vector<int> days(N);

		for (int i = 0; i < N; i++)
		{
			cin >> days[i];
		}

		for (auto iter = days.rbegin(); iter != days.rend(); ++iter)
		{
			if (*iter > max_price) {
				max_price = *iter;
			}
			result += max_price - *iter;
		}

		cout << "#" << test_case << " " << result << endl;
	}
}