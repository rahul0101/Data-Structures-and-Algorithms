#include <iostream>
#include <vector>

using std::vector;

vector<int> lcs3(vector<int> &a, vector<int> &b) {
  //write your code here
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

  int i = m; int j = n; k = mat[m][n]-1;
  vector<int> lcs(mat[m][n]);

  while(i>-1 && j>-1)
  {
    if(a[i-1] == b[j-1])
    {
      lcs[k] = a[i-1];
      i--;j--;k--;
    }
    else
    {
      if(mat[i-1][j] > mat[i][j-1])
				{
					i = i-1;
				}
			else
				{
					j = j-1;
				}
    } 
  }

  /*for(int i=0;i<lcs.size();i++)
  {
    std::cout<<lcs[i]<< " ";
  }
  */
  return lcs;
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }

  vector<int> ab(0);
  vector<int> abc(0);

  ab = lcs3(a, b);

  abc = lcs3(ab,c);

  int q = abc.size();

  ab = lcs3(b, c);

  abc = lcs3(ab,a);

  int w = abc.size();

  ab = lcs3(c, a);

  abc = lcs3(ab,b);

  int e = abc.size();

  if(q==0 || w==0 || e==0)
  {
    std::cout<<0;
  }
  else
  {
  std::cout << std::max(std::max(q,w),e) << std::endl;
  }
}
