#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>> v, int vertex, vector<bool> &visited)
{
  visited[vertex] = true;
  cout << vertex << " ";
  for (auto adj : v[vertex])
  {
    if (visited[adj] == false)
    {
      DFS(v, adj, visited);
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
  DFS(v, 1, visited);
  return 0;
}
