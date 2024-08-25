/*
Description
You and some monsters are in a matrix. When taking a step to some direction in the matrix, each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.
Your task is to find out if your goal is possible, and if it is, print the shortest length of the path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.

Input Format
The first input line has two integers n and m: the height and width of the matrix.
After this, there are n lines of m characters describing the matrix. Each character is ‘.’ (floor), ‘#’ (wall), ‘A’ (start), or ‘M’ (monster). There is exactly one ‘A’ in the input.

Output Format
First, print "YES" if your goal is possible, and "NO" otherwise.
If your goal is possible, also print the length of the shortest path that you'll follow.

Constraints
1 ≤ n, m ≤ 1000

Sample Input 1
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######
Sample Output 1
YES
5
Sample Input 2
3 3
###
#A#
#M.
Sample Output 2
NO
Sample Input 3
1 3
##A
Sample Output 3
YES
0
*/


#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

vector<vector<char>> mat;
vector<vector<int>> dis,personDis;
using state = pair<int,int>;

int main() {
    int n,m;
    cin >> n >> m;
    mat.resize(n,vector<char>(m));
    dis.resize(n,vector<int>(m,1e9));
    personDis.resize(n,vector<int>(m,1e9));
    // input
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    // direction
    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};

    // MSSP for monters
    queue<state> q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] == 'M'){
                q.push({i,j});
                dis[i][j] = 0;
            }

    while(!q.empty()){
        state u = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int xx = u.F + dx[i];
            int yy = u.S + dy[i];
            if(xx < 0 || xx >= n || yy < 0 || yy >= m || mat[xx][yy] != '.' || dis[xx][yy] != 1e9) continue;

            dis[xx][yy] = dis[u.F][u.S] + 1;
            q.push({xx,yy});
        }
    }

    // SSSP for person A
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] == 'A'){
                q.push({i,j});
                personDis[i][j] = 0;
            }

    while(!q.empty()){
        auto u = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int xx = u.F + dx[i];
            int yy = u.S + dy[i];
            if(xx < 0 || xx >= n || yy < 0 || yy >= m || mat[xx][yy] != '.' || personDis[xx][yy] != 1e9) continue;

            personDis[xx][yy] = personDis[u.F][u.S] + 1;
            q.push({xx,yy});
        }
    }

    int ans = 1e9;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                if(personDis[i][j] < dis[i][j]){
                    ans = min(ans,personDis[i][j]);
                }
            }

    if(ans == 1e9){
        cout << "NO";
    }
    else{
        cout << "YES\n" << ans;
    }


    return 0;
}