#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<int> graph[n+1],inorder(n+1,0);
    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        inorder[v]++;
    }

    priority_queue<int> mn_pq;
    for(int i=1; i<=n; i++){
        if(inorder[i]==0){
            mn_pq.push(-i);
        }
    }

    vector<int> ans;
    while(!mn_pq.empty()){
        int u=-mn_pq.top(); mn_pq.pop();
        ans.push_back(u);

        for(int v : graph[u]){
            inorder[v]--;
            if(inorder[v]==0){
                mn_pq.push(-v);
            }
        }
    }

    if(ans.size()==n){
        for(int i : ans) cout<<i<<" ";
    }
    else cout<<-1;



    return 0;
}