#include <bits/stdc++.h>
using namespace std;

// int main() {
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++) arr[i]=i+1;
//     do{
//         for(int i:arr) cout<<i<<" ";
//         cout<<"\n";
//     } while(next_permutation(arr.begin(),arr.end()));

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int n;
multiset<int> mt;
vector<int> ans;

void solve(int i){
    if(i==n){
        for(int i:ans) cout<<i<<" "; cout<<'\n';
        return;
    }
    for(int j=1; j<=n; j++){
        if(mt.find(j)==mt.end()){
            mt.insert(j);
            ans.push_back(j);
            solve(i+1);
            mt.erase(mt.find(j));
            ans.pop_back();
        }
    }
}



int main() {
    cin>>n;
    solve(0);
    return 0;
}