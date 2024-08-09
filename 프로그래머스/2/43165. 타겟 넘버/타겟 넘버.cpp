#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;

void solve(int cur, int sum, int target, const vector<int> &numbers){
    if(cur==numbers.size()){
        if(target==sum) answer++;
        return;
    }
    int num = numbers[cur];
    solve(cur+1,sum+num,target,numbers);
    solve(cur+1,sum-num,target,numbers);
}

int solution(vector<int> numbers, int target) {
    
    solve(0,0,target,numbers);
    
    return answer;
}