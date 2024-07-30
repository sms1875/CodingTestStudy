#include<iostream>

using namespace std;

int n;
int cnt;
bool col[13];
bool ldru[25];//n*2
bool lurd[25];

void func(int rw) {
	if (rw == n) {
		cnt++;
		return;
	}
	for (int cl = 0; cl < n; cl++)
	{
		if (col[cl]) continue;
		if (ldru[rw + cl]) continue;
		if (lurd[rw - cl + n - 1]) continue;
		col[cl] = true;
		ldru[rw + cl] = true;
		lurd[rw - cl + n - 1] = true;
		func(rw + 1);
		col[cl] = false;
		ldru[rw + cl] = false;
		lurd[rw - cl + n - 1] = false;
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++){
		cin >> n;
		cnt = 0;
		func(0);
		cout << "#" << i << " " << cnt << "\n";
	}
	return 0;
}