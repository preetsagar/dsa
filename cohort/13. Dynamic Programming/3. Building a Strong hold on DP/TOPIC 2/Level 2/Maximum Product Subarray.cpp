#include <bits/stdc++.h>
using namespace std;

#define int long long

int tc,n;
int arr[110000];

signed main() {
    cin>>tc; while(tc--){
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        int mx = arr[0], mn = arr[0], ans = arr[0];

        for(int i=1; i<n; i++){
            int tmp_mn = mn;
            mn = min(mx*arr[i], min(arr[i], mn*arr[i]));
            mx = max(mx*arr[i], max(arr[i], tmp_mn*arr[i]));
            // cout<<"("<<mn<<" ,"<<mx<<") ";
            ans = max(ans, mx);
        }
        // cout<<'\n';
        cout<<ans<<'\n';
    }
    return 0;
}