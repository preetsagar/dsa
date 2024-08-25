/*
Description
Your city is having people infected with a virus. The city in which you live is represented as a grid consisting of n rows and m columns. Cells containing 2 are the cells where the people infected with the virus are present and the cells having 1 are the cells having people not yet infected with the virus. There are certain empty cells which are represented by 0. The infected people in a unit time can infect all their adjacent cells, i.e, if they are present at cell [i, j] they can infect cells [i-1, j], [i+1, j], [i, j-1] and [i, j+1]. The virus cannot pass through empty cells. Your task is to print the minimum time in which all the people are infected with the virus. If the virus cannot infect everyone, print -1.

Input Format
The first line contains two integers n and m  — the number of rows and columns, respectively.
The following n lines contain m integers each, the j-th element in the i-th line is the number written in the j-th cell of the i-th row.

Output Format
Print the minimum time in which everyone can be infected or -1 if everyone cannot be infected.

Constraints
1 <= n <= 1000
1 <= m <= 1000
Sample Input 1
3 3
0 1 2
0 1 2
1 1 2
Sample Output 1
2
Sample Input 2
3 3
0 1 2
0 1 2
1 0 2
Sample Output 2
-1
*/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

vector<vector<int>> mat,dis;
using state = pair<int,int>;

int main() {
    int n,m;
    cin >> n >> m;
    mat.resize(n,vector<int>(m));
    dis.resize(n,vector<int>(m,1e9));

    // input
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    // direction
    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};

    // MSSP for infected people
    queue<state> q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] == 2){
                q.push({i,j});
                dis[i][j] = 0;
            }

    while(!q.empty()){
        state u = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int xx = u.F + dx[i];
            int yy = u.S + dy[i];
            if(xx < 0 || xx >= n || yy < 0 || yy >= m || mat[xx][yy] != 1 || dis[xx][yy] != 1e9) continue;

            dis[xx][yy] = dis[u.F][u.S] + 1;
            q.push({xx,yy});
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] == 1){
                ans = max(ans,dis[i][j]);
            }

    cout << (ans == 1e9 ? -1 : ans);
    return 0;
}