#include <bits/stdc++.h>

using namespace std;

long long solution(int r1, int r2) {
   long long answer=0;
    
    answer -= r2-r1+1;
    
    long long R1 = (long long)r1*r1;
    long long R2 = (long long)r2*r2;
    
    for(int x=0;x<=r2;x++){
        long long xx = (long long)x*x;
        int t1, t2 = sqrt(R2-xx);
        if(x<r1){
            double td = sqrt(R1-xx);
            int ti = sqrt(R1-xx);
            t1 = td>(double)ti?ti+1:ti;
        }else{
            t1 = 0;
        }
        answer += t2 - t1 + 1;
    }
    
    return answer*4;
}