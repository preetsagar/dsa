#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<string> maze;
pair<int,int> start;

queue<pair<int,int>> monster,human;
vector<vector<int>> monsterDis,humanDis;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int main(){
    cin>>n>>m;
    monsterDis.assign(n,vector<int>(m,1e9));
    humanDis.assign(n,vector<int>(m,1e9));

    for(int i=0; i<n; i++){
        string str; cin>>str;
        maze.push_back(str);

        for(auto j=0; j<m; j++){
            if(str[j]=='M'){
                monster.push({i,j});
                monsterDis[i][j]=0;
            }
            else if(str[j]=='A'){
                start={i,j};
                humanDis[i][j]=0;
            }
        }
    }

    // monster MS BFS
    while(!monster.empty()){
        auto u=monster.front(); monster.pop();
        int ui=u.first;
        int uj=u.second;

        for(int i=0; i<4; i++){
            int vi=ui+dx[i];
            int vj=uj+dy[i];

            if(vi>=0&&vi<n&&vj>=0&&vj<m&&maze[vi][vj]!='#'){
                if(monsterDis[vi][vj]==1e9){
                    monsterDis[vi][vj]=1+monsterDis[ui][uj];
                    monster.push({vi,vj});
                }
            }
        }
    }

    // BFS for human
    human.push(start);
    while(!human.empty()){
        auto u=human.front(); human.pop();
        int ui=u.first;
        int uj=u.second;

        for(int i=0; i<4; i++){
            int vi=ui+dx[i];
            int vj=uj+dy[i];

            if(vi>=0&&vi<n&&vj>=0&&vj<m&&maze[vi][vj]!='#'){
                if(humanDis[vi][vj]==1e9){
                    humanDis[vi][vj]=1+humanDis[ui][uj];
                    human.push({vi,vj});
                }
            }
        }
    }

    // check for exit point 
    int minDisForPerson=1e9;
    int isPossibe=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0||i==n-1||j==0||j==m-1){
                if(maze[i][j]!='#'){
                    if(monsterDis[i][j]>humanDis[i][j]){
                        isPossibe=1;
                        minDisForPerson=min(minDisForPerson,humanDis[i][j]);
                    }
                }
            }
        }
    }

    if(isPossibe){
        cout<<"YES\n"<<minDisForPerson;
    }
    else cout<<"NO";

    return 0;
}