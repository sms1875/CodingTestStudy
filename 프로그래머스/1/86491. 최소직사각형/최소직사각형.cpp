#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w=1,h=1;
    for(const auto& s:sizes){
        int weight=max(s[0],s[1]);
        int height=min(s[0],s[1]);
        
        w=max(weight,w);
        h=max(height,h);
    }
    answer=w*h;
    
    return answer;
}