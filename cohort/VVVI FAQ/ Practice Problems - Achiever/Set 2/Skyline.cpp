#include <bits/stdc++.h>
using namespace std;

int t, n;
map<int, vector<int>> mp;
multiset<int> length;


int main() {
    cin>>t;
    while(t--){
        cin>>n;
        mp.clear();
        length.clear();
        vector<pair<int, int>> ans;

        int st, ed, len;
        for(int i=0; i<n; i++){
            cin>>st>>ed>>len;
            mp[st].push_back(len);
            mp[ed].push_back(-len);
        }

        int lastLen = -1;
        for(auto i:mp){
            for(int j:i.second){
                if(j>0){
                    length.insert(j);
                }else{
                    length.erase(length.find(-j));
                }
            }
            int currLen = length.empty() ? 0 : *length.rbegin();
            if(lastLen != currLen){
                cout<<i.first<<" "<<currLen<<"\n";
                lastLen = currLen;
            }
        }
        cout<<"\n";

    }
    return 0;
}