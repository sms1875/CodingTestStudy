#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >>n>>m;
    
    vector<vector<int>> d (n+2,vector<int>(n+2,10000001));
    while(m--){
        int a,b,c;
        cin >>a>>b>>c;
        d[a][b]=min(d[a][b],c);
    }
    for(int i=1;i<=n;i++){
        d[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[i][j]>10000000) cout <<"0 ";
            else cout <<d[i][j]<<' ';
        }
        cout <<'\n';
    }
}