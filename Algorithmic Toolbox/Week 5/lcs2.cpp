#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  int m = a.size(); int n = b.size();
  int k = 0;
  int mat[m+1][n+1];

  for(int i=0;i<m+1;i++)
  {
    for(int j=0;j<n+1;j++)
    {
      mat[i][j] = 0;
    }
  }

  for(int i=1;i<m+1;i++)
  {
    for(int j=1;j<n+1;j++)
    {
      if(a[i-1] == b[j-1])
      {
        mat[i][j] = mat[i-1][j-1] + 1;
        continue;
      }

      mat[i][j] = std::max(mat[i-1][j], mat[i][j-1]);
    }
  }

  /*for(int i=0;i<m+1;i++)
  {
    for(int j=0;j<n+1;j++)
    {
      std::cout<<mat[i][j]<<" ";
    }
    std::cout<<"\n";
  }*/

  return mat[m][n];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
