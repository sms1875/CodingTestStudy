#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T, tc;
int N;
int diff;
int myOperator[4];
int nums[13];

int usingOp;
const int ADD = 0;
const int SUB = 1;
const int MUL = 2;
const int DIV = 3;

int maxVal = -21e8;
int minVal = 21e8;

void init()
{
	memset(myOperator, -1, sizeof(myOperator));
	memset(nums, 0, sizeof(nums));
}

void input()
{
	cin >> N;
	// 연산자 input
	for (int i = 0; i < 4; i++)
	{
		cin >> myOperator[i];
	}
	// 피 연산자 input
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
}

void DFS(int lev, int val)
{
	if (lev == N)
	{
		if (maxVal < val)
		{
			maxVal = val;
		}
		if (minVal > val)
		{
			minVal = val;
		}
		diff = maxVal - minVal;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (myOperator[i] == 0) continue;
		myOperator[i]--;
		usingOp = i;
		switch (usingOp)
		{
		case ADD:
			DFS(lev + 1, val + nums[lev]);
			break;
		case SUB:
			DFS(lev + 1, val - nums[lev]);
			break;
		case MUL:
			DFS(lev + 1, val * nums[lev]);
			break;
		case DIV:
			DFS(lev + 1, val / nums[lev]);
			break;
		}
		myOperator[i]++;
	}
}

void solve()
{
	maxVal = -21e8;
	minVal = 21e8;
	DFS(1, nums[0]);
}

void output()
{
	cout << "#" << tc << " " << diff << "\n";
}
int main()
{
	cin >> T;
	for (tc = 1; tc <= T; tc++)
	{
		init();
		input();
		solve();
		output();
	}

	return 0;
}