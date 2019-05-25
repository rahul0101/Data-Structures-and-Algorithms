#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int cap, vector<int> &w, vector<int> &v) {
  double value = 0.0;
  int a,W = cap;
  int n = w.size();

  for(int i =0; i<n-1; i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if( ((double)v[j+1])/w[j+1] > ((double)v[j])/w[j] )
      {
        int temp1 = w[j];
        w[j] = w[j+1];
        w[j+1] = temp1;

        int temp2 = v[j];
        v[j] = v[j+1];
        v[j+1] = temp2;
      }
    }
  }

  /*for(int i=0;i<n;i++)
  {
    std::cout<<"!!"<<w[i]<<"--"<<v[i]<<"\n";
  }*/

  for(int i=0;i<n;i++)
  {
    if(W==0)
      return value;

    if(w[i]>=W){a = W;}
    else {a = w[i];}

    value += ((double)a/(double)w[i])*(double)v[i];

    w[i] = w[i] - a;
    
    W = W - a;
    //std::cout<<"--"<<A[i]<<"\n";
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
