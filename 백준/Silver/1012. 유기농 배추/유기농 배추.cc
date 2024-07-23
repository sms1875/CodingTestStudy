#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
  int Tcase;
  cin >> Tcase;
  while (Tcase--)
  {
    int res = 0;

    int x, y, cnt;
    cin >> x >> y >> cnt;

    int board[50][50] = {0};
    bool vis[50][50] = {false};

    while (cnt--)
    {
      int a, b;
      cin >> a >> b;
      board[a][b] = 1;
    }
    
    for (int i = 0; i < x; i++)
    {
      for (int j = 0; j < y; j++)
      {
        if (board[i][j] == 1 && vis[i][j] == 0)
        {
          res++;
          queue<pair<int, int>> q;
          vis[i][j] = 1;
          q.push({i, j});
          int size = 0;
          while (!q.empty())
          {
            size++;
            auto cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
              int nx = cur.first + dx[dir];
              int ny = cur.second + dy[dir];
              if (nx < 0 || nx >= x || ny < 0 || ny >= y)
                continue;
              if (vis[nx][ny] || board[nx][ny] != 1)
                continue;
              vis[nx][ny] = 1;
              q.push({nx, ny});
            }
          }
        }
      }
    }
    cout << res << '\n';
  }
}