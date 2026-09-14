
#include <bits/stdc++.h>
using namespace std;

#define int long long

long long findArithmeticSeq(int a[], int n)
{
    map<pair<int, int>, int> mp; // {idx, cDiff} -> no of subsequen
    int ans=0;
    int mod = 1e9+7;
    
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){
            int cd = a[i]-a[j];
            int last = mp[{j, cd}];
            mp[{i, cd}] = (mp[{i, cd}] + 1 + last) % mod;

            // adding last here because it counts len >=2
            ans += (last);
        }
    }

    return ans%mod;
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << findArithmeticSeq(a, n) << '\n';
    return 0;
}
