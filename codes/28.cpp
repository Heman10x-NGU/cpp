#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    long long k;
    cin>>n>>k;

    multiset<long long> qs;
    for(int i=0;i<n;i++){
        long long val;
        cin>>val;
        qs.insert(val);
    }
    vector<long long> rs(n);
    for(int i=0;i<n;i++){
        cin>>rs[i];
    }
    sort(rs.begin(), rs.end());

    int ans=0;

    for(long long r:rs){
        if(qs.empty()){
            break;
        }

        long long limit=(k-r)/(r+1);

        auto it=qs.upper_bound(limit);

        if(it==qs.begin()){
            continue;
        }

        it--;

        qs.erase(it);
        ans++;
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}