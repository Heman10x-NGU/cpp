#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;


    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];

        }

        vector<int> trail;
        int totaldig=0;

        for(int i=0;i<n;i++){
            string s=to_string(a[i]);
            int count=0;
            totaldig += s.size();
            int j=s.size()-1;
            while(j>=0 && s[j]=='0'){
                count++;
                j--;
            }
            trail.push_back(count);
        }

        sort(trail.rbegin(),trail.rend());
        int del=0;
        for(int i=0;i<trail.size();i++){
            if(i%2==0){
                del += trail[i];
            }
        }

        int ans=totaldig-del;

        ans>=m+1?cout<<"Sasha"<<endl:cout<<"Anna"<<endl;
    }
}