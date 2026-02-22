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
vector<int> perm;
vector<bool> used(20, 0);

void solve(int i){
    if(i==n){
        for(int x : perm) cout<<x<<" ";
        cout<<'\n';
        return;
    }

    for(int j=1; j<=n; j++){
        if(!used[j]){
            used[j] = true;
            perm.push_back(j);
            solve(i+1);
            used[j] = false;
            perm.pop_back();
        }
    }
}

int main() {
    cin>>n;
    solve(0);
    return 0;
}