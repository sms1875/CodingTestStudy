#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    map<string,vector<string>> m;
    map<string,int> reportmap;
    
    sort(report.begin(),report.end());
    report.erase(unique(report.begin(),report.end()),report.end());

    for(const auto& rp:report){
        int space=rp.find(" ");
        string a=rp.substr(0,space);
        string b=rp.substr(space+1,rp.size()-1);
        m[a].emplace_back(b);
        reportmap[b]++;
    }
    
    for(int i=0;i<id_list.size();i++){
        int sum=0;
        for(auto id:m[id_list[i]]){
            if(reportmap[id]>=k)
                sum++;
        }
        answer[i]=sum;
    }

    
    return answer;
}