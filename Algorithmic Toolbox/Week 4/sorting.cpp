#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

vector<int> partition3(vector<int> &a, int l, int r) {
  int x = a[l];
    int ab = l;
    int i = l;
    int cd = r;
    vector<int> m(2);
    while (i <= cd) {
        if (a[i] < x) {
            swap(a[ab], a[i]);
            ab++;
            i++;
        } else if (a[i] == x) {
            i++;
        } else {
            swap(a[i], a[cd]);
            cd--;
        }
        m[0] = ab;
        m[1] = cd;
    }
    return m;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector<int> m = partition3(a, l, r);

  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
