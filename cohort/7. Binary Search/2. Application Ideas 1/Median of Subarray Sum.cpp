#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<int> arr;

bool check(int mid){
    int t = (n*(n+1))/2;
    t = (t+1)/2;
    int count=0;
    // we need prefixSun for this
    // for(int i=0; i<n; i++){
    //     int x = i>0 ? mid+arr[i-1] : mid;
    //     count += upper_bound(arr.begin(), arr.end(), x) - (arr.begin()+i);
    // }
    // return count >= t;
    int head=-1, tail=0, sum=0;
    while(tail<n){
        while(head+1<n && sum+arr[head+1]<=mid){
            head++; sum += arr[head];
        }
        count += (head-tail+1);
        if(tail>head){
            tail++; head = tail-1;
        }else{
            sum -= arr[tail];
            tail++;
        }
    }
    return count >= t;
}


signed main() {
    int t; cin>>t; while(t--){
        cin>>n;
        arr.resize(n);
        int sum=0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            sum += arr[i];
        }

        int l=0, r=sum;
        int ans=0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(check(mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}