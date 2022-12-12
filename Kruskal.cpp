#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

vector<pair<int,pair<int, int>>> edges;
unordered_map<int, int> parents;

int find(int x)
{
  if (parents[x] == x)
    return x;
  return parents[x] = find(parents[x]);
}

void union_(int x, int y)
{
  parents[find(x)] = find(y);
}

void kruskal()
{
  sort(edges.begin(), edges.end());

  vector<pair<int, int>> mst;

  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    int weight = edges[i].first;

    if (find(u) != find(v))
    {
      union_(u, v);
      mst.push_back({u, v});
    }
  }

  for (int i = 0; i < mst.size(); i++)
  {
    cout << mst[i].first << " " << mst[i].second << endl;
  }
}

int main()
{
  int n, m;
  cin >> n >> m;

  edges.reserve(m);

  for (int i = 0; i < m; i++)
  {
    int u, v, weight;
    cin >> u >> v >> weight;
    edges.push_back({weight, {u, v}});
  }

  for (int i = 0; i < n; i++)
  {
    parents[i] = i;
  }
  kruskal();

  return 0;
}
