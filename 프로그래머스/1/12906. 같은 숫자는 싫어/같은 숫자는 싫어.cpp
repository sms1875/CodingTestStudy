#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer (1,10);

    for(int i=0;i<arr.size();i++){
        if(answer.back()!=arr[i])
            answer.push_back(arr[i]);
    }
    answer.erase(answer.begin());

    return answer;
}