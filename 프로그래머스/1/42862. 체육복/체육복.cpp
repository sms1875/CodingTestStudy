#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    
    for(int i=0;i<lost.size();i++){
        for(int j=0;j<reserve.size();j++){
            if(lost[i]==reserve[j]){
                lost[i]=-1;
                reserve[j]=-1;
            }
        }       
    }
         
    for(int i=0;i<lost.size();i++){
        for(int j=0;j<reserve.size();j++){
            if(lost[i]-reserve[j] == 1){
                lost[i]=-1;
                reserve[j]=-1;
            }
            else if(lost[i]-reserve[j] == -1){
                lost[i]=-1;
                reserve[j]=-1;
            }
        }
              
    }
    
    while(find(lost.begin(),lost.end(),-1)!=lost.end()){
        lost.erase(find(lost.begin(),lost.end(),-1));
    }
    
    return n-lost.size();
}