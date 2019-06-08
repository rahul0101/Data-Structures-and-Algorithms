#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  
  int x=0;

  int q = W+1;

  vector<int> value((w.size()+1)*(W+1));

  for(int i=0;i<=W;i++)
  {
    value[0*q+i] = 0;
  }

  for(int i=0;i<=w.size();i++)
  {
    value[i*q+0] = 0;
  }

  for(int i=1;i<=w.size();i++)
  {
    for(int j=1;j<=W;j++)
    {
      value[i*q+j] = value[(i-1)*q+j];

      if(w[i-1] <= j)
      {
        x = value[(i-1)*q+(j-w[i-1])] + w[i-1];

        if(value[i*q+j] < x)
        {
          value[i*q+j] = x;
        }
      }
    }
  }

  return value[w.size()*q+W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
