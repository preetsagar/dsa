#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

int n,m;
using ll=long long;
vector<pair<int,pair<int,ll>>> edge;
vector<ll> dis;
bool negCycle=false;

void bellmanFord(){
    dis[1]=0;
    for(int i=1; i<n; i++){
        for(auto j:edge){
            ll u=j.F;
            ll v=j.S.F;
            ll wt=j.S.S;

            if(dis[v]>dis[u]+wt){
                dis[v]=dis[u]+wt;
            }
        }
    }

    for(auto j:edge){
        ll u=j.F;
        ll v=j.S.F;
        ll wt=j.S.S;

        if(dis[v]>dis[u]+wt){
            negCycle=true;
        }
    }
}

int main() {
    cin>>n>>m;
    dis.assign(n+1,1e18);
    for(int i=0; i<m; i++){
        int a,b,wt;
        cin>>a>>b>>wt;
        edge.push_back({a,{b,-wt}});
    }
    bellmanFord();

    if(negCycle){
        cout<<"-1";
    }
    else{
        cout<<-dis[n];
    }
    return 0;
}