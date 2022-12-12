#include <iostream>
#include <list>
#include <vector>

using namespace std;

void BFS(vector<vector<int>> v, int vertex, vector<bool> &visited)
{
  list<int> queue;
  visited[vertex] = true;
  queue.push_back(vertex);

  while (!queue.empty())
  {
    vertex = queue.front();
    cout << vertex << " ";
    queue.pop_front();
    for (auto adj : v[vertex])
    {
      if (!visited[adj])
      {
        visited[adj] = true;
        queue.push_back(adj);
      }
    }
  }
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> v(n + 1);
  vector<bool> visited(n + 1, false);
  for (int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  BFS(v, 1, visited);
  return 0;
}
