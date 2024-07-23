#include <bits/stdc++.h>
using namespace std;

vector<int> adj[32001];
int deg[32001];
int n,m;

int main (){
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;// 4 3  , 4 1
        adj[a].push_back(b);//adj[4]=3,1
        deg[b]++;//deg[1]=1 , deg[3]=1
    }
    
    queue<int> q;  
    for(int i = 1; i <= n; i++){
        if(deg[i] == 0) q.push(i);//2, 4 
    }
  
    while(!q.empty()){
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for(int nxt : adj[cur]){ 
            deg[nxt]--;
          if(deg[nxt] == 0) q.push(nxt);     
        }
    }
}