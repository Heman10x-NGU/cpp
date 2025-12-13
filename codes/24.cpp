#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<long long> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        if(k>=3){
            cout<<0<<endl;
            continue;
        }
        
        sort(v.begin(),v.end());
        vector<long long> diff;
        long long mmin=v[0];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long d=(v[j]-v[i]);
                diff.push_back(d);
                mmin=min(mmin,d);
            }
        }
        if(k==1){
            cout<<mmin<<endl;
            continue;
        }
        long long ans=mmin;
        sort(diff.begin(),diff.end());

        for(int i=0;i<diff.size();i++){
            long long x=diff[i];
            int lb=lower_bound(v.begin(),v.end(),x)-v.begin();

           
                ans=min(ans, v[lb]-x);
            
            
            // Check the element before the one found (closest smaller element)
            if(lb > 0){
                ans=min(ans, x-v[lb-1]);
            }
        }

        cout<<ans<<endl;

    }
}