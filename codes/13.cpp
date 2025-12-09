#include <bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int x;
        cin>>x;
        int flag=false;

        if (n == 1) {
            cout << (arr[0] == x ? "YES\n" : "NO\n");
            continue;
        }
        for(int i=0;i+1<n;i++){
            int mini=min(arr[i],arr[i+1]);
            int maxi=max(arr[i],arr[i+1]);
            if(x>=mini && x<=maxi){
                flag=true;
                break;
            }
        }
        if(flag==false){
            cout<<"NO"<<"\n";
        }
        else
        cout<<"YES"<<"\n";

    }
}