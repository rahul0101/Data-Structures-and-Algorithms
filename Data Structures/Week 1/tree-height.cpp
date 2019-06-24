#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

int fill(vector<int> &parents, int i, vector<int> &visited, vector<int> &heights)
{
  if(parents[i] == -1)
  {
    visited[i] = 1;
    return 0;
  }

  if(visited[i])
  {
    return heights[i];
  }

  visited[i] = 1;

  heights[i] = 1 + fill(parents,parents[i],visited,heights); 

  return heights[i];
}

int find_height(vector<int> &parents)
{
  int mh = 0;
  vector<int> visited;
  vector<int> heights;
  for(int i=0;i<parents.size();i++)
  {
    visited.push_back(0);
    heights.push_back(0);
  }

  for(int i=0;i<parents.size();i++)
  {
    if(!visited[i])
    {
      heights[i] = fill(parents, i, visited, heights);
    }

    if(heights[i]>mh)
    {
      mh = heights[i];
    }
  }

  return mh+1;  
}

int main()
{
  vector<int> parents;
  int n,x;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>x;
    parents.push_back(x);
  }

  cout<<find_height(parents);
}
