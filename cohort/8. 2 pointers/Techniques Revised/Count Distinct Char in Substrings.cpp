#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t; while(t--){
        int n; cin>>n;
        string s; cin>>s;
        vector<int> index[26];
        for(int i=0; i<26; i++) index[i].push_back(-1);
        for(int i=0; i<n; i++){
            index[s[i]-'a'].push_back(i);
        }
        for(int i=0; i<26; i++) index[i].push_back(n);

        // charecter kis kis index pe present hai
        // for(int i=0; i<26; i++){
        //     if(index[i].size()>2){
        //         cout<<char('a'+i)<<" -> ";
        //         for(auto j:index[i]) cout<<j<<" "; cout<<"\n";
        //     }
        // }

        long long ans=0;
        long long total=(n*(n+1))/2;
        for(int i=0; i<26; i++){
            if(index[i].size()>2){
                long long notPresentInSubarray=0;
                for(int j=1; j<index[i].size(); j++){
                    int l=index[i][j]-index[i][j-1]-1;
                    notPresentInSubarray+=(l*(l+1))/2;
                }
                ans+=(total-notPresentInSubarray);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}