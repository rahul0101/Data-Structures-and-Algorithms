#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &a, const string &b) {
  //write your code here
  int m = a.length(); int n = b.length();
  int k = 0;
  int mat[m+1][n+1];

  for(int i=0;i<m+1;i++)
  {
    mat[i][0] = i;
  }

  for(int j=0;j<n+1;j++)
  {
    mat[0][j] = j;
  }

  int x = 0;
  for(int i=1;i<m+1;i++)
  {
    for(int j=1;j<n+1;j++)
    {
      if(a[i-1] == b[j-1])
      {
        mat[i][j] = mat[i-1][j-1];
        continue;
      }

      x= std::min(mat[i-1][j], mat[i][j-1]);
      mat[i][j] = std::min(mat[i-1][j-1],x) + 1;
    }
  }

  return mat[m][n];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
