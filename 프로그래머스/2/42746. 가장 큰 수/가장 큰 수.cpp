#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> arr;
    for(const auto& n:numbers){
        arr.push_back(to_string(n));
    }
    sort(arr.begin(),arr.end(),[](string a,string b){
        return a+b>b+a;
    });
    for(const auto& n:arr){
        answer+=n;
    }
    if(answer[0]=='0') return "0";
    return answer;
}