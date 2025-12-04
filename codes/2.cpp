#include <bits/stdc++.h>
using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;


    while(t--){

        long long x,y,z;

        cin >> x >> y >> z;



        long long invalid = (x & y & ~z) || (~x & y & z) || (x & ~y & z);
        

        if(invalid == 0){
            cout<< "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}