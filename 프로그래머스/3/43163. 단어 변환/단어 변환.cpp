#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 21e8;
bool visited[51];

bool checkString(const string& a, const string& b) {
    int count = 0;

    for (int i = 0; i < a.length(); ++i) {
        if (a[i] == b[i]) {
            count++;
        }
    }
    if(count == a.length() - 1) return true;
    return false;
}

void solve(string cur, string target,int cnt, const vector<string> &words){
    if(cnt>=answer) return;
    if(cur==target){
        answer=min(cnt,answer);
    }
    for(int i =0; i<words.size();i++){
        if(visited[i]) continue;
        string word = words[i];
        if(checkString(cur,word)){
            visited[i]=true;
            solve(word,target,cnt+1,words);
            visited[i]=false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    if(find(words.begin(),words.end(),target)==words.end()) return 0;
    solve(begin,target,0,words);
    return answer;
}