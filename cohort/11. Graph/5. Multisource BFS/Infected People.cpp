#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> city,infectedDis;

queue<pair<int,int>> infected;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int main(){
    cin>>n>>m;
    city.assign(n,vector<int>(m));
    infectedDis.assign(n,vector<int>(m,1e9));

    for(int i=0; i<n; i++){
        for(auto j=0; j<m; j++){
            int temp; cin>>temp;
            city[i][j]=temp;
            if(temp==2){
                infected.push({i,j});
                infectedDis[i][j]=0;
            }
        }
    }

    // infected MS BFS
    while(!infected.empty()){
        auto u=infected.front(); infected.pop();
        int ui=u.first;
        int uj=u.second;

        for(int i=0; i<4; i++){
            int vi=ui+dx[i];
            int vj=uj+dy[i];

            if(vi>=0&&vi<n&&vj>=0&&vj<m&&city[vi][vj]!=0){
                if(infectedDis[vi][vj]==1e9){
                    infectedDis[vi][vj]=1+infectedDis[ui][uj];
                    infected.push({vi,vj});
                }
            }
        }
    }

    int isPossibeToInfect=1;
    int mxTimeToInfact=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(city[i][j]==1&&infectedDis[i][j]==1e9){
                isPossibeToInfect=0;
            }
            if(city[i][j]==1&&infectedDis[i][j]!=1e9){
                mxTimeToInfact=max(mxTimeToInfact,infectedDis[i][j]);
            }
        }
    }

    if(isPossibeToInfect){
        cout<<mxTimeToInfact;
    }
    else cout<<"-1";

    return 0;
}