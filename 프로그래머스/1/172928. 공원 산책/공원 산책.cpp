#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer={0,0};
    queue<string> q;
    
    for(int i=0;i<park.size();i++){ 
        for(int j=0;j<park[i].size();j++){
            if(park[i][j]=='S'){
                answer[0]=i;
                answer[1]=j;
            }
        }
    }
    
    while(!routes.empty()){
        string r = routes.front();
        char op = r[0]; r.erase(r.begin());
        int n = stoi(r);
        bool flag=true;
        
        if(op=='E'){
            for(int i=1;i<=n;i++){
                if(answer[1]+i>=park[answer[0]].size()){
                    flag=false;
                    break;
                }
                else if(park[answer[0]][answer[1]+i]=='X') {
                    flag=false;
                    break;
                }
            }
            if(flag) answer[1]+=n;
        }
        else if(op=='W'){
            for(int i=1;i<=n;i++){
                if(answer[1]-i<0){
                    flag=false;
                    break;
                }
                else if(park[answer[0]][answer[1]-i]=='X') {
                    flag=false;
                    break;
                }
            }
            if(flag) answer[1]-=n;
        }
        else if(op=='S'){
            for(int i=1;i<=n;i++){
                if(answer[0]+i>=park.size()){
                    flag=false;
                    break;
                }
                else if(park[answer[0]+i][answer[1]]=='X') {
                    flag=false;
                    break;
                }
            }
            if(flag) answer[0]+=n;
        }
        else if(op=='N'){
            for(int i=1;i<=n;i++){
                if(answer[0]-i<0){
                    flag=false;
                    break;
                }
                else if(park[answer[0]-i][answer[1]]=='X') {
                    flag=false;
                    break;
                }
            }
            if(flag) answer[0]-=n;
        }
        routes.erase(routes.begin());
    }
    
    
    
    return answer;
}