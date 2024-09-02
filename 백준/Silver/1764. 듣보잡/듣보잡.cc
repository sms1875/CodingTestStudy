#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>


using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	string person;
	unordered_map<string,int> people;
	vector<string> ans;

	for (int i = 0; i < a; i++) {
		cin >> person;
		people[person]++;
	}
	for (int i = 0; i < b; i++)
	{
		cin >> person;
		if (people[person])
			ans.push_back(person);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}
}