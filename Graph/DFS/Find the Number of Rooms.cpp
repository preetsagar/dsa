/*
Description
You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n × m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.

Input Format
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either ‘.’ (floor) or '#' (wall).

Output Format
Print one integer: the number of rooms.

Constraints
1 ≤ n, m ≤ 1000

Sample Input 1
5 8
########
#..#...#
####.#.#
#..#...#
########
Sample Output 1
3
*/

#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<char>> arr;
vector<vector<int>> vis;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
void DFS(int i,int j) {
    vis[i][j] = 1;
    for(int it = 0; it < 4; it++) {
        int x = i + dx[it];
        int y = j + dy[it];
        if(x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0 &&
            arr[x][y] == '.') {
            DFS(x,y);
        }
    }
}

int main() {
    cin >> n >> m;
    arr.resize(n,vector<char>(m));
    vis.resize(n,vector<int>(m,0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && arr[i][j] == '.') {
                count++;
                DFS(i,j);
            }
        }
    }
    cout << count;

    return 0;
}