#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){

        int n;

        cin>>n;

        vector<int> b(n);

        set<int> distinct_beauties;

        for(int i=0;i<n;i++){
            cin>>b[i];

            distinct_beauties.insert(b[i]);
        }

        cout << distinct_beauties.size() << "\n";
    }

    return 0;
}
