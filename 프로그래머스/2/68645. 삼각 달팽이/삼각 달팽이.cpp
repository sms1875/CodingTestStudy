#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> map (1000,(vector<int>(1000,0)));

void insertMap(int n){
    int dir_type = 0;
    int count = 1;
    int sum = 0;
    
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    
    queue<pair<int,int>> q;
    
    map[0][0]=1;
    if(n==1) return;
    
    q.push({0,0});
    
    while(!q.empty()){
        if(count == sum) break;
        
        auto [x,y]= q.front();
        q.pop();
        
        switch(dir_type){
            case 0:
                x ++;
                if(map[x][y]!= 0 || x == n){
                    dir_type = 1;
                    q.push({x-1,y++});
                }
                else {
                    map[x][y]=++count;
                    q.push({x,y});
                }
                break;
            case 1:
                y ++;
                if(map[x][y]!= 0 || y == n){
                    dir_type = 2;
                    q.push({x,y-1});
                }
                else {
                    map[x][y]=++count;
                    q.push({x,y});
                }
                break;
            case 2: 
                x --; y--;
                if(map[x][y]!= 0){
                    dir_type = 0;
                    q.push({x+1 ,y+1});
                }
                else {
                    map[x][y]=++count;
                    q.push({x,y});
                }
                break;
        }
    }
}

vector<int> solution(int n) {
    vector<int> answer;
    insertMap(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){ 
            answer.push_back(map[i][j]);
        }
    }
    
    return answer;
}