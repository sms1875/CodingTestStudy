#include <bits/stdc++.h>

using namespace std;

int main()
{
  int count;
  cin >> count;
  while (count--)
  {
    string str;
    cin >> str;

    list<char> editer;
    auto cursor = editer.end();

    for (auto c : str)
    {
      switch (c)
      {
      case '<':
      {
        if (cursor != editer.begin())
          cursor--;
        break;
      }
      case '>':
      {
        if (cursor != editer.end())
          cursor++;
        break;
      }
      case '-':
      {
        if (cursor != editer.begin())
        {
          cursor--;
          cursor = editer.erase(cursor);
        }
        break;
      }
      default:
      {
        editer.insert(cursor, c);
        break;
      }
      }
    }
    for (auto c: editer) cout << c;
    cout << endl;
  }
}