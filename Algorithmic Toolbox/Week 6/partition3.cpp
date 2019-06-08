#include <iostream>
#include <vector>

using std::vector;

int partition3(int w, int n, vector<int> &A) {
  //write your code here
  int count = 0;
  int temp = 0;
  int value[w+1][n+1];
  for(int i=0;i<w+1;i++)
  {
    for(int j=0;j<n+1;j++)
    {
      value[i][j] = 0;
    }
  }

  for(int i=1;i<w+1;i++)
  {
    for(int j=1;j<n+1;j++)
    {
      value[i][j] = value[i][j-1];
      if(A[j-1]<=i)
      {
        temp = value[i-A[j-1]][j-1] + A[j-1];
        if(temp>value[i][j])
        {
          value[i][j] = temp;
        }
      }
      if(value[i][j] == w)
      {
        count+=1;
      }
    }
  }

  if(count<3){return 0;}
  return 1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  int sum = 0;
  for(int i=0;i<A.size();i++)
  {
    sum += A[i];
  }
  if(n<3){std::cout<<0;}
  else if(sum%3 != 0){std::cout<<0;}
  else {std::cout << partition3(sum/3,n,A) << '\n';}
}
