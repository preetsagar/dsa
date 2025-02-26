
#include <bits/stdc++.h>
using namespace std;


#define F first
#define S second

using state=pair<int,int>;

int n;
vector<vector<int>> dis,vis;

bool isValid(int x,int y){
    if(x>0&&x<=n&&y>0&&y<=n) return true;
    return false;
}

int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};

vector<state> neighbour(state u){
    vector<state> arr;
    for(int i=0; i<8; i++){
        int x=u.F+dx[i];
        int y=u.S+dy[i];

        if(isValid(x,y)){
            arr.push_back({x,y});
        }
    }
    return arr;
}

void BFS(state st){
    queue<state> q;
    q.push(st);
    vis[st.F][st.S]=1;
    dis[st.F][st.S]=0;

    while(!q.empty()){
        state u=q.front(); q.pop();

        for(state v : neighbour(u)){
            if(!vis[v.F][v.S]){
                vis[v.F][v.S]=1;
                q.push(v);
                dis[v.F][v.S]=dis[u.F][u.S]+1;
            }
        }
    }
}

int KnightWalk(int N,int Sx,int Sy,int Fx,int Fy){
    n=N;
    vis.assign(N+1,vector<int>(N+1,0));
    dis.assign(N+1,vector<int>(N+1,-1));
    BFS({Sx,Sy});
    // cout<<dis[Fx][Fy]<<endl;
    return dis[Fx][Fy];
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin>>test_case;

    while(test_case--){
        int N,Sx,Sy,Fx,Fy;
        cin>>N>>Sx>>Sy>>Fx>>Fy;

        cout<<KnightWalk(N,Sx,Sy,Fx,Fy)<<"\n";
    }
}
