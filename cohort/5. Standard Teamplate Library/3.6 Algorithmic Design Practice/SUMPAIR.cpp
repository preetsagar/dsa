#include <bits/stdc++.h>
using namespace std;
#define int long long

class FindPairswithSum{
    map<int,int> mapA,mapB;
    vector<int> arrB;
public:

    FindPairswithSum(vector<int>& A,vector<int>& B){
        for(int i : A) mapA[i]++;
        for(int i : B) mapB[i]++;
        arrB=B;
    }

    void add(int index,int val){
        int oldVal=arrB[index];
        int newVal=arrB[index]+val;
        arrB[index]+=val;
        mapB[oldVal]--;
        if(mapB[oldVal]==0) mapB.erase(oldVal);
        mapB[newVal]++;
    }

    int count(int total){
        int ans=0;
        for(auto i:mapA){
            if(mapB.find(total-i.first)!=mapB.end()){
                ans+=(mapA[i.first]*mapB[total-i.first]);
            }
        }
        return ans;
    }
};


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,q;
    cin>>n>>m>>q;

    vector<int> A(n),B(m);

    for(auto& i:A){
        cin>>i;
    }

    for(auto& i:B){
        cin>>i;
    }

    FindPairswithSum* obj=new FindPairswithSum(A,B);

    for(int i=0; i<q; i++){
        string op;
        cin>>op;
        if(op=="add"){
            int index,val;
            cin>>index>>val;
            obj->add(index,val);
        }
        else{
            int total;
            cin>>total;
            cout<<obj->count(total)<<'\n';
        }
    }

    return 0;
}
