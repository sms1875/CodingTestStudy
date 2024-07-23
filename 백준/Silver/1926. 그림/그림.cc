#include <bits/stdc++.h>
using namespace std;

int board[502][502]; 
bool vis[502][502]; 
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 

int main() {
    int n,m;
    int cnt=0;
    int max_size=0;
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j]==1 && vis[i][j]==0){
                cnt++;
                queue<pair<int,int> > q;
                vis[i][j]=1;
                q.push({i,j});
                int size=0;
                while(!q.empty()){
                    size++;
                    auto cur = q.front();
                    q.pop();
                    for(int dir=0; dir<4; dir++){
                        int nx= cur.first+dx[dir];
                        int ny= cur.second+dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny] || board[nx][ny] != 1) continue; 
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
                max_size=max(size,max_size);
            }
        }
    }
     cout << cnt << '\n' << max_size;
}