#include <bits/stdc++.h>
using namespace std;

int main(){
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
        for(int i=0; i<26; i++){
            if(index[i].size()>2){
                for(int j=1; j<index[i].size()-1; j++){
                    int l=index[i][j]-index[i][j-1];
                    int r=index[i][j+1]-index[i][j];
                    ans+=l*r;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}