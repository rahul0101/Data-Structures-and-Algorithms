#include <iostream>
#include<limits>

int get_change(int m) {
  //write your code here
  int a[3] = {1,3,4};

  int min_coins[m+1];
  min_coins[0] = 0;
  int num_coins = 0;

  for(int i=1;i<=m;i++)
  {
    min_coins[i] = std::numeric_limits<int>::max();

    for(int j=0;j<3;j++)
    {
      if(i>=a[j])
      {
          num_coins = min_coins[i-a[j]] + 1;

          if(num_coins < min_coins[i])
          {
            min_coins[i] = num_coins;
          }
      }
    }
  }

  return min_coins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
