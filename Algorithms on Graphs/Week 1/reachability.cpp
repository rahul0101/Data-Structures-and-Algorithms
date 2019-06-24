#include <iostream>
#include <vector>
#include<list>

using std::list;
using std::vector;
using std::pair;


int reach(vector<vector<int> > &adj, int x, int y) {
  if(x==y){return 1;}
  vector<int> visited(adj.size());
  list<int> queue;
  visited[x] = 1;
  queue.push_back(x);

  //vector<int>::iterator i;

  while(!queue.empty())
  {
    x = queue.front();
    queue.pop_front();
    int elem;

    for(int i = 0; i!=adj[x].size(); ++i)
    {
      elem = adj[x].at(i);

      if(elem == y){ return 1;}

      if(!visited[elem])
      {
        visited[elem] = 1;
        queue.push_back(elem);
      }
    }
  } 

  return 0;
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
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
