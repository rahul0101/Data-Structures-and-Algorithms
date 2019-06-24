#include <iostream>
#include <vector>

using std::vector;
using std::pair;


void DFS(int v, vector<int> &visited, vector<vector<int> > &adj)
{
  visited[v] = 1;

  for(int i=0; i!=adj[v].size(); ++i)
  {
    int elem = adj[v].at(i);

    if(!visited[elem])
    {
      //visited[elem] = 1;
      DFS(elem, visited, adj);
    }
  }
}

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  //write your code here
  vector<int> visited(adj.size());

  for(int v=0; v<adj.size(); v++)
  {
    if(!visited[v])
    {
      DFS(v, visited, adj);
      res++;
    }
  }

  return res;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
