#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        long long x= LLONG_MAX/2;
        long long y= LLONG_MAX/2;
        int ans=0;

        for(auto val:a){
            if(x>y){
                swap(x,y);
            }

            if(val<=x){
                x=val;
            }
            else if(val<=y){
                y=val;
            }
            else{
                x=val;
                ans++;
            }
        }

        cout<<ans<<endl;
    }
}