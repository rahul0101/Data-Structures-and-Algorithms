#include <iostream>
using namespace std;
int get_change(int m) {
  int a[3],x,y;
  a[0]=0;a[1]=0;a[2]=0;
  x = m%10;
  a[0] = (m/10);
  if(x!=0)
  {
    y = x % 5;
    a[1] = (x / 5);
    
    if(y!=0)
    {
      a[2] = y;
    }
  }
  return a[0]+a[1]+a[2];
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
