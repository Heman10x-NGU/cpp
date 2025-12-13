#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void solve() {
    int n;
    ll k;
    cin >> n >> k;
    
    vector<int> a(n);
    vector<int> v(64, n);  // v[i] = count of elements without bit i set
    int ans = 0;
    
    // Read input array
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Count initial beauty and track missing bits
    for(int i = 0; i < 31; i++) {
        for(int j = 0; j < n; j++) {
            if(a[j] & (1LL << i)) {
                v[i]--;  // This element HAS bit i, so one less element needs it
                ans++;   // Add to current beauty count
            }
        }
    }
    
    // Greedy: Buy the cheapest bits first (lower bit positions)
    for(int i = 0; i < 64; i++) {
        // Cost to set bit i is (2^i) per element
        ll cost_per_bit = (1LL << i);
        ll affordable = k / cost_per_bit;  // How many bits can we afford?
        
        if(affordable < v[i]) {
            // Can't afford all missing bits at position i
            ans += affordable;
            break;
        } else {
            // Buy all missing bits at position i
            ans += v[i];
            k -= v[i] * cost_per_bit;
        }
    }
    
    cout << ans << '\n';
}
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
