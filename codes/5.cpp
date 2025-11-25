// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     int t;
//     cin >> t;
    
//     while(t--){
//         int n;
//         cin >> n;
        
//         vector<long long> b(n);
//         for(int i = 0; i < n; i++){
//             cin >> b[i];
//         }
        
//         vector<int> a(n + 1);  // 1-indexed
//         int next_new_value = 1;
        
//         for(int i = 1; i <= n; i++){
//             long long diff;
//             if(i == 1){
//                 diff = b[0];  // b[1] - 0
//             } else {
//                 diff = b[i-1] - b[i-2];
//             }
            
//             if(diff == i){
//                 // This is a new distinct element
//                 a[i] = next_new_value;
//                 next_new_value++;
//             } else {
//                 // This element is same as a[i - diff]
//                 a[i] = a[i - diff];
//             }
//         }
        
//         // Output the result
//         for(int i = 1; i <= n; i++){
//             cout << a[i];
//             if(i < n) cout << " ";
//         }
//         cout << "\n";
//     }
    
//     return 0;
// }






#include <bits/stdc++.h>
using namespace std;

using int64 = long long;          

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCount;
    cin >> testCount;

    while (testCount--) {

        
        int n;
        cin >> n;
        vector<int64> b(n + 1, 0);          
        for (int i = 1; i <= n; ++i) cin >> b[i];

       
        vector<int> a(n + 1, 0);            
        int nextUnusedValue = 1;             
        bool possible = true;

        for (int i = 1; i <= n && possible; ++i) {

            int64 delta = b[i] - b[i - 1];  
            int previousPosition = int(i - delta);   

            if (delta <= 0 || delta > i) {  
                possible = false; break;
            }

            if (previousPosition == 0) {     
                if (nextUnusedValue > n) {   
                    possible = false; break;
                }
                a[i] = nextUnusedValue++;
            } else {                         
                a[i] = a[previousPosition];
            }
        }


        for (int i = 1; i <= n; ++i) {
            if (i > 1) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}