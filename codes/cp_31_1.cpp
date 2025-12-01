#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> a1=a;
        sort(a1.begin(),a1.end());

        if(a1==a){
            cout<<"YES"<<"\n";
            continue;
        }

        if(k==1 ){
            cout<<"NO"<<"\n";
        }
        else {
            cout<<"YES"<<"\n";
        }

    }
}