#include <bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){
        int n,x;
        cin>>n>>x;

        vector<int> a(n+2);
        a[0]=0;
        a[n+1]=x;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }

        int ans=1;
        for(int i=0;i+1<n+2;i++){
            int d=a[i+1]-a[i];
            if(i==n){
                d=2*d;
            }
            ans=max(ans,d);
        }
        
        cout<<ans<<"\n";
    }
}