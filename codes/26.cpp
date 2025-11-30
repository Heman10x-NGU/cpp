#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
    } 
    else if (n == 2) {
        
        cout << 9 << endl;
    } 
    else {
       
        long long edge_cost = 4 * n * n - n - 4;

        
        long long interior_cost = 5 * n * n - 5 * n - 5;

        
        cout << max(edge_cost, interior_cost) << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}