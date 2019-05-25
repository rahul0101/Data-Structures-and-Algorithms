#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long MaxPairwiseProduct(const  vector<long>& numbers) {
    
    int max_index1 = -1;
    int max_index2 = -1;
    int n = numbers.size();

    for(int i=0; i<n; i++)
    {
        if(max_index1 == -1  || numbers[i]>numbers[max_index1])
        {
            max_index1 = i;
        }
    }

    for(int i=0; i<n; i++)
    {
        if(max_index1 == i)
            continue;
        
        if(max_index2 == -1 || numbers[i]>numbers[max_index2])
        {
            max_index2 = i;
        }
    }

    long long prod = (long long)numbers[max_index1]*numbers[max_index2];

    //cout<<max_index1<<" "<<max_index2;

    return prod;
}

int main() {
    int n;
     cin >> n;
     vector<long> numbers(n);
    for (int i = 0; i < n; ++i) {
         cin >> numbers[i];
    }

    long long res = MaxPairwiseProduct(numbers);

     cout << res << "\n";
    return 0;
}
