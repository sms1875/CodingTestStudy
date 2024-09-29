#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> arr;
    for(int i=0;i<progresses.size();i++){
        int day=1;
        int p=progresses[i];
        while(p<100){
            p+=speeds[i];
            day++;
        }
        arr.push_back(day);
        
    }
    while(!arr.empty()){
        int cnt=1;
        int day=arr.front();
        arr.erase(arr.begin());
        
        while(arr.front()<=day && !arr.empty()){
            arr.erase(arr.begin());
            cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}