#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int total,cur,last;
    total = 0; cur = 0; last = 0;
    stops.insert(stops.begin(),0);
    stops.insert(stops.end(), dist);
    int max = tank; int n = stops.size() - 1;
    while(cur<=n)
    {
        last = cur;
        while(cur<=n && (stops[cur+1] - stops[last]) <= max)
        {
            cur += 1;
        }

        //std::cout<<cur<<"  "<<last<<"\n";
        if(cur == last)
            return -1;

        if(cur == n)
            break;    

        if(cur<=n)
            total += 1;            
    }
    return total;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
