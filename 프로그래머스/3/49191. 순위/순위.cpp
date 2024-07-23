#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> graph (n+1,vector<int>(n+1,-1));
    
    // 자기 자신과 경기 0
    for(int i=1; i<n+1; i++){
        graph[i][i]=0;
    }
    
    // 승리 1, 패배 2
    for(auto res : results){
        graph[res[0]][res[1]]=1;
        graph[res[1]][res[0]]=2;
    }
    
    for(int k=1; k<= n; k++){
        for(int win=1; win<=n ; win++){
            for(int lose=1; lose<=n; lose++){
                if (graph[win][k] == 1 && graph[k][lose] == 1){
                    graph[win][lose] = 1;
                }
                else if (graph[k][win] == 2 && graph[win][lose] == 2){
                    graph[k][lose] = 2;
                }
            }
        }
    }
        
    for(int k=1; k<= n; k++){
        for(int win=1; win<=n ; win++){
            for(int lose=1; lose<=n; lose++){
                if (graph[win][k] == 1 && graph[k][lose] == 1){
                    graph[win][lose] = 1;
                }
                else if (graph[k][win] == 2 && graph[win][lose] == 2){
                    graph[k][lose] = 2;
                }
            }
        }
    }
    
    for(int win=1; win<n+1; win++){
        bool isFill = true;
        for(int lose=1; lose<n+1; lose++){
            if(graph[win][lose] == -1) isFill = false;
        }
        if(isFill) answer++;
    }
    
    return answer;
}