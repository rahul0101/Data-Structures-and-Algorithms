#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> calc(int n) {
  std::vector<int> seq;
  std::vector<int> v;

  if(n==1)
  {
    v.push_back(1);
    return v;
  }

  seq.push_back(1);
  int index = -1;
  int i=0;
  while(i>=0)
  {
    seq.push_back(seq[i]+1);
    seq.push_back(seq[i]*2);
    seq.push_back(seq[i]*3);

    if(seq[3*i+1]==n)
    {
      index = 3*i+1;
      break;
    }

    if(seq[3*i+2]==n)
    {
      index = 3*i+2;
      break;
    }

    if(seq[3*i+3]==n)
    {
      index = 3*i+3;
      break;
    }

    i++;
  }

  while(index>=1)
  {
    v.push_back(seq[index]);
    index /= 3;
  }

  v.push_back(1);
  reverse(v.begin(), v.end());
  return v;

}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = calc(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
