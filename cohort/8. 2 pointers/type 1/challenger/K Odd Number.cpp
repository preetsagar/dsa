#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;cin>>t; while(t--){
        int n,k,d; cin>>n>>k>>d;
        vector<int> A(n),preFix(n);
        for(int i=0; i<n; i++){
            cin>>A[i];
            preFix[i]=A[i];
            if(i) preFix[i]+=preFix[i-1];
        }

        int head=-1,tail=0,ans=-1e18,odd=0;
        multiset<int> mt;
        while(tail<n){
            while((head+1<n)&&(odd<k||A[head+1]%2==0)){
                head++;
                if(A[head]%2) odd++;
                mt.insert(preFix[head]);
            }
            int base=(tail==0) ? 0 : preFix[tail-1];
            auto it=mt.upper_bound(d+base);
            if(it!=mt.begin()){
                it--;
                ans=max(ans,*it-base);
            }

            if(tail>head){
                tail++;
                head=tail-1;
            }
            else{
                if(A[tail]%2) odd--;
                mt.erase(mt.find(preFix[tail]));
                tail++;
            }
        }
        if(ans==-1e18) cout<<"IMPOSSIBLE\n";
        else cout<<ans<<"\n";
    }
    return 0;
}