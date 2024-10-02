#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;while(t--){
        int n,q; cin>>n>>q;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        while(q--){
            int ch,x; cin>>ch>>x;
            if(ch==1){
                auto it=(lower_bound(arr.begin(),arr.end(),x));
                if(it==arr.end()) cout<<"-1 ";
                else cout<<*(it)<<" ";
            }
            else if(ch==2){
                auto it=upper_bound(arr.begin(),arr.end(),x);
                if(it==arr.end()) cout<<"-1 ";
                else cout<<*(it)<<" ";
            }
            else if(ch==3){
                cout<<(upper_bound(arr.begin(),arr.end(),x)-arr.begin())<<" ";
            }
            else if(ch==4){
                cout<<(lower_bound(arr.begin(),arr.end(),x)-arr.begin())<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}