#include <bits/stdc++.h>
using namespace std;

int highestBit(int64_t x)           
{
    return 63 - __builtin_clzll(x); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;                         
    cin >> T;
    while (T--) {
        long long a, b;
        cin >> a >> b;

        int msbA = highestBit(a);
        int msbB = highestBit(b);

        
        if (msbB > msbA) {          
            cout << -1 << '\n';
            continue;
        }

        vector<long long> ops;      
        long long cur = a;

        
        for (int i = 0; i <= msbA; ++i) {
            int bitCur = (cur >> i) & 1;
            int bitB   = (b   >> i) & 1;
            if (bitCur != bitB) {
                long long x = 1LL << i;   
               
                cur ^= x;
                ops.push_back(x);
            }
        }

        
        if (cur != b) {
            cerr << "logic error: result mismatch\n";
            return 0;
        }

        
        cout << ops.size() << '\n';
        if (!ops.empty()) {
            for (size_t i = 0; i < ops.size(); ++i) {
                if (i) cout << ' ';
                cout << ops[i];
            }
            cout << '\n';
        }
    }
    return 0;
}