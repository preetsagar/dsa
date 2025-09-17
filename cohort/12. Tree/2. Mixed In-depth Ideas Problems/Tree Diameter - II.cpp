#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, reqDis, cnt;
vector<vector<int>> g;
int dep[200010];
int par[200010];

void dfs(int node, int parent, int depth){
    dep[node] = depth;
    par[node] = parent;

    for(int v:g[node]){
        if(v!=parent){
            dfs(v, node, depth+1);
        }
    }
}

void dfs2(int node, int parent, int depth){
    if(depth == reqDis) cnt++;
    for(int v:g[node]){
        if(v!=parent){
            dfs2(v, node, depth+1);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    if(n==1){   // this was causing runtime issue
        cout<<1; return 0;
    }
    g.resize(n+1);
    for(int i=1; i<n; i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Find Diameter
    int d1 = 1, dis=0, d2;
    dfs(1, 0, 0);
    for(int i=1; i<=n; i++){
        if(dis < dep[i]){
            dis = dep[i];
            d1 = i;
        }
    }
    dis=0;
    dfs(d1, 0, 0);
    for(int i=1; i<=n; i++){
        if(dis < dep[i]){
            dis = dep[i];
            d2 = i;
        }
    }

    // Find Centre
    if(dis%2!=0){ // 2 centre
        int c1 = d2, c2;
        int step = dis/2;
        while(step--){
            c1 = par[c1];
        }
        c2 = par[c1];

        reqDis = dis/2;
        int cnt1, cnt2;

        cnt=0;
        dfs2(c1, c2, 0);
        cnt1 = cnt;

        cnt=0;
        dfs2(c2, c1, 0);
        cnt2 = cnt;

        cout<<cnt1 * cnt2;
    }
    else{ // 1 centre
        int steps = dis/2;
        int c = d2;
        while(steps--) c = par[c];

        vector<int> tmp;
        reqDis = dis/2;
        for(int v:g[c]){
            cnt=0;
            dfs2(v, c, 1);
            tmp.push_back(cnt);
        }

        int sum=0;
        for(int i:tmp) sum+=i;

        int ans =0;
        for(int i:tmp){
            sum -= i;
            ans += i * sum;
        }
        cout<<ans;
    }

    return 0;
}