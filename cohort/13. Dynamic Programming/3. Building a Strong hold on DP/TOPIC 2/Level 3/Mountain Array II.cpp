#include <bits/stdc++.h>
using namespace std;

int n,tc;
int arr[11000];

int main() {
    cin>>tc; while(tc--){
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        if(n<3) {cout<<-1<<'\n'; continue;}
        
        // LIS in nlogn ending at i [0..i]
        vector<int> lis(n), tmp;
        tmp.clear();
        {
            for(int i=0; i<n; i++){
                if(tmp.size()==0 || tmp.back()<arr[i]){
                    tmp.push_back(arr[i]);
                    lis[i] = tmp.size();
                }
                else{
                    auto it = lower_bound(tmp.begin(), tmp.end(), arr[i]);
                    *it = arr[i];
                    lis[i] = it-tmp.begin()+1;
                }
            }
        }
        
        // Longest Decreasing Seq in nlogn starting at i [i..n]
        tmp.clear();
        vector<int> lds(n);
        {
            for(int i=n-1; i>=0; i--){
                if(tmp.size()==0 || tmp.back()<arr[i]){
                    tmp.push_back(arr[i]);
                    lds[i] = tmp.size();
                }
                else{
                    auto it = lower_bound(tmp.begin(), tmp.end(), arr[i]);
                    *it = arr[i];
                    lds[i] = it-tmp.begin()+1;
                }
            }
        }

        int len = -1;
        for(int i=0; i<n; i++){
            if(lis[i]>1 && lds[i]>1){
                len = max(len, lis[i]+lds[i]-1);
            }
        }
        cout<<(len<3 ? -1 : n-len)<<'\n';
    }
    return 0;
}