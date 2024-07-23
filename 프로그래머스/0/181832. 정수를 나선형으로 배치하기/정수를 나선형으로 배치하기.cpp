#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n));

    int num = 1; 
    int x = 0, y = 0; 
    int direction = 0; 
    
    for (int i = 0; i < n * n; i++) {
        answer[y][x] = num; 

        if (direction == 0) {
            if (x == n - 1 || answer[y][x + 1] != 0) {
                direction = 1;
                y++;
            } else {
                x++;
            }
        } else if (direction == 1) {
            if (y == n - 1 || answer[y + 1][x] != 0) {
                direction = 2;
                x--;
            } else {
                y++;
            }
        } else if (direction == 2) {
            if (x == 0 || answer[y][x - 1] != 0) {
                direction = 3;
                y--;
            } else {
                x--;
            }
        } else if (direction == 3) {
            if (y == 0 || answer[y - 1][x] != 0) {
                direction = 0;
                x++;
            } else {
                y--;
            }
        }

        num++;
    }

    return answer;
}