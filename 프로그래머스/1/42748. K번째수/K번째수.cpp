#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(const auto& v:commands){
        vector<int> arr;
        arr.assign(array.begin() + v[0] -1, array.begin() + v[1]);
        sort(arr.begin(),arr.end());
        answer.push_back(arr[v[2]-1]);
    }
    return answer;
}