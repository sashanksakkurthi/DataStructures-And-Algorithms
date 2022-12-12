#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<vector<pair<int, int>>> adj;

void prim(int source, vector<pair<int, int>> &edges)
{
  vector<bool> visited(adj.size(), false);
  priority_queue<pair<int, int>> pq;
  pq.push({0, source});

  while (!pq.empty())
  {
    int u = pq.top().second;
    pq.pop();

    if (visited[u])
      continue;
    visited[u] = true;

    for (int i = 0; i < adj[u].size(); i++)
    {
      int v = adj[u][i].first;
      int weight = adj[u][i].second;

      if (!visited[v])
      {
        pq.push({-weight, v});
        edges.push_back({u, v});
      }
    }
  }
}

int main()
{
  int n, m, source;
  cin >> n >> m >> source;

  adj.resize(n);

  for (int i = 0; i < m; i++)
  {
    int u, v, weight;
    cin >> u >> v >> weight;
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
  }

  vector<pair<int, int>> edges;
  prim(source, edges);

  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i].first;
    int v = edges[i].second;
    cout << "Edge: " << u << " " << v << endl;
  }

  return 0;
}
