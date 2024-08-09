#include<vector>
#include<queue>
#include <iostream>
using namespace std;

int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};
int N,M;

int bfs(const vector<vector<int>> &maps){
    queue<pair<int,int>> q;
    int visited[101][101]={0};
    int res = 21e8;
    
    q.push({0,0});
    visited[0][0]=1;
    cout<<N << " "<<M<<endl;
    while(!q.empty()){
        pair<int,int> cur =q.front();
        q.pop();
        if(cur.first == N-1 && cur.second == M-1){
            res=visited[cur.first][cur.second];
            break;
        }
        for(int i=0; i<4; i++){
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            
            if(ny<0||nx<0||ny>=N||nx>=M)continue;
            if(maps[ny][nx]==0) continue;
            if(visited[ny][nx]) continue;
            
            visited[ny][nx]=visited[cur.first][cur.second]+1;
            q.push({ny,nx});
        }
    }
    
    if(res==21e8) res=-1;
    
    return res;
}

int solution(vector<vector<int>> maps)
{
    N = maps.size(); M = maps[0].size();
    int answer = 0;
    answer = bfs(maps);
    return answer;
}