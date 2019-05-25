#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here

  int T = n-1;
  int x = 1;

  if(n==2)
  {
    summands.push_back(2);
    return summands;
  }

  summands.push_back(x);

  while(T != 0)
  {
    if((x+1 + x+2) <= T)
    {
      summands.push_back(x+1);
      T -= x+1;
      x = x+1;
    }
    else
    {
      summands.push_back(T);
      break;
    }
  }

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
