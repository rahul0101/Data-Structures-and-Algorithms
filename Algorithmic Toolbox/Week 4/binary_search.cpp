#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x, int low, int high) {
  //write your code here
  //std::cout<<mid<<"\n";

  if(low <= high)
  {

  int mid = low + (high-low)/2;    

  if(x == a[mid])
  {
    return mid;
  }
  else if (x<a[mid])
  {
    return binary_search(a, x, low, mid-1);
  }
  else
  {
    return binary_search(a, x, mid+1, high);
  }

  }

  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  int low = 0, high = (int)a.size(); 
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i], low, high-1) << ' ';
  }
}
