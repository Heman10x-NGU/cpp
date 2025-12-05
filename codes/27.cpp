#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    long long sum_b = 0;
    long long non_zero_count = 0;
    
    for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sum_b += x;
        if (x > 0) {
            non_zero_count++;
        }
    }
    
    long long limit_width = non_zero_count;
    long long limit_sum = sum_b - (n - 1);
    
    cout << min(limit_width, limit_sum) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}