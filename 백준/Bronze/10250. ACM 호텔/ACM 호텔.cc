#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T,H,W,N,room; cin>>T;
    while(T!=0){
    cin>>H>>W>>N;
    if(N%H==0)
        room=H*100+ceil((double)N/H);
    else
        room=(N%H)*100+ceil((double)N/H);
    cout<<room<<'\n';
    T--;
    }
}