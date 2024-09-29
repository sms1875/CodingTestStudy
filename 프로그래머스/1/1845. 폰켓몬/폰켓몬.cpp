#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int,int> m;
    
    for(const auto& n:nums){
        m[n]++;
    }
    
    int size=nums.size()/2;
    
    if(m.size()<size)
        return m.size();
    else 
        return size;
}