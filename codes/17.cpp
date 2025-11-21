#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &x:a) cin>>x;
        sort(a.begin(),a.end());
        bool ok=true;
        for(int i=1;i+1<n;i+=2) if(a[i]!=a[i+1]){ ok=false; break; }
        cout<<(ok?"YES\n":"NO\n");
    }
}