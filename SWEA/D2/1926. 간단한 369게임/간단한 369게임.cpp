#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


int main(int argc, char** argv)
{
	int n;
	cin >> n;

	for (int i = 1; i < n + 1; i++)
	{
		int a = i;
		int cnt = 0;
		while (a) {
			int b = a % 10;
			a /= 10;
			if (b == 3 || b == 6 || b == 9) cnt++;
		}
		if (cnt) {
			while (cnt--)
				cout << "-";

			cout << " ";
		}
		else {
			cout << i << " ";
		}
	}

	return 0;
}