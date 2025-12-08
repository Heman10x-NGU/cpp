#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        char l=s[n-1];
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]==l){
                count++;
            }
        }

        int ans=n-count;

        cout<<ans<<endl;


    }
}