#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        vector<int> b(n);
        a[0]=1;
        for(int i=1;i<n;i++){
            cin>>a[i];
        }

        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int ans=0;
        int ptra=0;
        int matches=0;
        for(int i=0;i<n;i++){
            if(a[ptra]<b[i]){
                ans++;
                ptra++;
            }
            
        }
        
        cout<<n-ans<<endl;
        

    }
}