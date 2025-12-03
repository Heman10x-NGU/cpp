#include <bits/stdc++.h>
using namespace std;


bool canReach(vector<pair<int,int>> v,int k){

    int cur_step=v[0].first;
    if(cur_step>k){
        return false;
    }
    int n=v.size();
   // cout<<k<<endl;
    for(int i=1;i<n;i++){
        int first_d=abs(v[i].first-cur_step);
        int second_d=abs(v[i].second-cur_step);
        int m=min(first_d,second_d);
        if(abs(m)>k){
            return false;
        }
        
        // cout<<m<<",";
        cur_step=v[i].first;
    }
    //cout<<"true;"<<endl;
    return true;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<pair<int,int>> v(n);

        for(int i=0;i<n;i++){
            cin>>v[i].first>>v[i].second;
        }

        int low=v[0].first;
        int high=INT_MIN;
        for(int i=0;i<n;i++){
            high=max(high,v[i].second);
        }

        while(low<high){
            int mid = low + (high-low)/2;

            if(canReach(v,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        //cout<<endl;
        cout<<low<<endl;
    }
}