/*
Description
You have been given a grid of size N x N. Each cell is either empty (.) or occupied (#). Size of each cell is 1 x 1. In the connected component, you can reach any cell from every other cell in the component by repeatedly stepping to adjacent cells in the north, south, east, and west directions.
Your task is to find the area and perimeter of the connected component having the largest area. The area of a connected component is just the number of '#' characters that are part of it. If multiple connected components tie for the largest area, find the smallest perimeter among them.

Input Format
The first line of input contains N, and the next N lines describe the grid. At least one '#' character will be present.

Output Format
Please output one line containing two space-separated integers, the first being the area of the largest connected component, and the second being its perimeter. If multiple connected components tie for the largest area, print the one which has the smallest perimeter among them.

Constraints
1 ≤ N ≤ 1000

Sample Input 1
6
##....
....#.
.#..#.
.#####
...###
....##
Sample Output 1
13 22
*/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define MP make_pair

vector<vector<char>> mat;
vector<vector<int>>  col;
using state = pair<int,int>;
int n;
queue<state> q;
int area = 0;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void DFS(state u,int color){
    q.push(u);
    col[u.F][u.S] = color;
    area++;
    for(int i = 0; i < 4; i++){
        int xx = u.F + dx[i];
        int yy = u.S + dy[i];
        if(xx < 0 || xx >= n || yy < 0 || yy >= n || col[xx][yy] || mat[xx][yy] == '.')  continue;
        DFS({xx,yy},color);
    }
}

int perimeter(state u){
    int count = 0;
    for(int i = 0; i < 4; i++){
        int xx = u.F + dx[i];
        int yy = u.S + dy[i];
        if(xx < 0 || xx >= n || yy < 0 || yy >= n || mat[xx][yy] == '.')  count++;
    }
    return count;
}

int main() {
    cin >> n;
    mat.resize(n,vector<char>(n));
    col.resize(n,vector<int>(n,0));
    // input
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    int peri = 0,final_peri = 0,final_area = 0;
    int color = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!col[i][j] && mat[i][j] == '#'){
                area = 0;
                DFS({i,j},color);
                color++;
                peri = 0;
                while(!q.empty()){
                    peri += perimeter(q.front());
                    q.pop();
                }
                if(area > final_area){
                    final_area = area;
                    final_peri = peri;
                }
                else if(area == final_area){
                    final_peri = min(final_peri,peri);
                }
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<col[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout << final_area << " " << final_peri;


    return 0;
}