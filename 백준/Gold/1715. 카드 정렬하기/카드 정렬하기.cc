#include <bits/stdc++.h>

using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;
    while(n--){
        int input;
        cin >> input;
        pq.push(input);
    }
    int sum=0;
    while(pq.size()>1){
        int a=pq.top(); pq.pop();
        int b=pq.top(); pq.pop();
        sum+=a+b;
        pq.push(a+b);
    }
    cout << sum;
}