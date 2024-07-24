#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int, vector<int>> map;
int N, M, V;

void bfs()
{
  unordered_map<int, bool> visited;
  queue<int> q;

  q.push(V);
  visited[V] = true;

  while (!q.empty())
  {
    int current = q.front();
    q.pop();
    for (int next : map[current])
    {
      if (!visited[next])
      {
        q.push(next);
        visited[next] = true;
      }
    }
    cout << current << " ";
  }
}

void dfs()
{
  unordered_map<int, bool> visited;
  stack<int> s;

  s.push(V);

  while (!s.empty())
  {
    int current = s.top();
    s.pop();

    if (!visited[current])
    {
      visited[current] = true;

      // 정점 번호가 작은 것을 먼저 방문하기 위해 스택에 큰 순서부터 넣음
      for (auto it = map[current].rbegin(); it != map[current].rend(); ++it)
      {
        if (!visited[*it])
        {
          s.push(*it);
        }
      }

      cout << current << " ";
    }
  }
}

void input()
{
  cin >> N >> M >> V;
  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    map[a].push_back(b);
    map[b].push_back(a);
  }

  for (auto &m : map)
  {
    sort(m.second.begin(), m.second.end());
  }
}

int main()
{

  input();
  dfs();
  cout << "\n";
  bfs();

  return 0;
}