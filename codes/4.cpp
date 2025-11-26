#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<int> a(n);
        
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        
        int mex = 0;  // Start with MEX = 0
        
        for(int i = 0; i < n; i++){
            if(a[i] == mex){
                mex++;  // Found the expected number, increment
            }
            // Skip duplicates and numbers > mex
        }
        
        cout << mex << endl;
    }
    
    return 0;
}
