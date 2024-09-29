#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int count = 0;  
    for (const auto &c : s) {
        if (c == '(') {
            count++;
        } else {
            count--;
            if (count < 0) return false;
        }       
    }
    return count==0?true:false;
}