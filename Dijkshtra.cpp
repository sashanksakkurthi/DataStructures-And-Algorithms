#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<vector<pair<int, int>>> adj;

void dijkstra(int source, vector<int>& dist) {
  dist.assign(adj.size(), INF);
  priority_queue<pair<int, int>> pq;
  dist[source] = 0;
  pq.push({0, source});

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    for (auto& edge : adj[u]) {
      int v = edge.first;
      int weight = edge.second;

      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push({-dist[v], v});
      }
    }
  }
}

int main() {
  int n, m, source;
  cin >> n >> m >> source;

  adj.resize(n);

  for (int i = 0; i < m; i++) {
    int u, v, weight;
    cin >> u >> v >> weight;
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
  }

  vector<int> dist;
  dijkstra(source, dist);

  for (int i = 0; i < n; i++) {
    cout << "Distance from node " << source << " to node " << i << " is " << dist[i] << endl;
  }
  return 0;
}
