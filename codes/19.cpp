// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     int t;
//     cin>>t;

//     while(t--){
//         string s;
//         cin>>s;

//         int n=s.size();
//         int dot=0;
//         int left=0,right=0;
//         int lmax=0;
//         int rmax=0;
//         if(n==1){
//             cout<<1<<endl;
//             continue;
//         }
//         int ans=1;
//         for(int i=0;i<n;i++){
//             if(s[i]=='*'){
//                 dot++;
//                 rmax=max(rmax,right);
//                 right=0;
//                 lmax=max(left,lmax);
//                 left=0;
//             }
//             else if(s[i]=='<'){
//                 left++;
//                 rmax=max(rmax,right);
//                 right=0;
//             }
//             else{
//                 right++;
//                 lmax=max(left,lmax);
//                 left=0;
//             }
//         }

//         if(dot==n && n>=2){
//             ans = -1;
//              cout<<-1<<endl;
//             continue;
//         }
//         int l1=-1,r1=-1;
//         for(int i=0;i<n;i++){
//             if(s[i]=='>'){
//                 l1=i;
//                 break;
//             }
           
//         }

//         for(int i=n-1;i>=0;i--){
//             if(s[i]=='<'){
//                 r1=i;
//                 break;
//             }
//         }

//         if(l1!=-1 && r1!=-1 && r1>l1){
//             cout<<-1<<endl;
//             continue;
//         }

//         ans=max(lmax,rmax);
//         cout<<ans<<endl;
//     }
// }






// #include <bits/stdc++.h>
// using namespace std;
// static inline bool cyc(char a,char b){return (a=='>'||a=='*')&&(b=='<'||b=='*');}
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int q;cin>>q;
//     while(q--){
//         string t;cin>>t;int m=t.size(),i;
//         bool loop=false;
//         for(i=0;i+1<m&&!loop;++i)loop=cyc(t[i],t[i+1]);
//         if(loop){cout<<-1<<"\n";continue;}
//         int l=0;while(l<m&&t[l]=='<')++l;
//         int r=0;while(r<m&&t[m-1-r]=='>')++r;
//         cout<<max(l,r)+(t.find('*')!=string::npos)<<"\n";
//     }
//     return 0;
// }


