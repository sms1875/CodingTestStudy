#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> temp;
    for (string name : participant)
    {  
        temp[name]++;
    }
    for (string name : completion)
    {
        temp[name]--;
    }
    for (auto pair : temp)
    {
        if (pair.second > 0)
        {
            answer = pair.first;
            break;
        }
    }
    return answer;
}