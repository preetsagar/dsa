#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
int finalArr[250010];
vector<int> smallArr[60];

struct max_val{
    int best=0, suffbest=0, prebest=0, sum=0;

    void build(vector<int> &arr){
        int t=0,n=arr.size();
        t = arr[0];
        prebest = t;
        for(int i=1; i<n; i++){
            t += arr[i];
            prebest = max(prebest, t);
        }

        t = arr[n-1];
        suffbest = t;
        for(int i=n-2; i>=0; i--){
            t += arr[i];
            suffbest = max(suffbest, t);
        }

        sum = 0;
        for(int i=n-1; i>=0; i--){
            sum += arr[i];
        }

        int currBest = arr[0];
        best = arr[0];
        for(int i=1; i<n; i++){
            currBest = max(arr[i], currBest+arr[i]);
            best = max(best, currBest);
        }
    }

    max_val merge_arr(max_val a){
        max_val ans;
        ans.best = max({best, a.best, suffbest+a.prebest});
        ans.suffbest = max(a.suffbest, suffbest+a.sum);
        ans.prebest = max(prebest, sum + a.prebest);
        ans.sum = sum + a.sum;
        return ans;
    }
};

max_val computed[60];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            smallArr[i].clear();
            int l;
            cin >> l;
            while (l--) {
                int x;
                cin >> x;
                smallArr[i].push_back(x);
            }
            computed[i].build(smallArr[i]);
        }
        for (int i = 0; i < m; i++) cin >> finalArr[i];

        max_val tmp = computed[finalArr[0]];
        int ans = tmp.best;
        for(int i=1; i<m; i++){
            tmp = tmp.merge_arr(computed[finalArr[i]]);
            ans = max(ans, tmp.best);
        }

        cout<<ans<<'\n';
    }
    return 0;
}