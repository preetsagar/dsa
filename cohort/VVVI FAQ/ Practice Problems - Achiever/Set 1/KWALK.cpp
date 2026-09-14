#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dis;
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
	dis.assign(N+1, vector<int>(N+1, 1e9));

    queue<pair<int, int>> q;
    q.push({Sx, Sy});
    dis[Sx][Sy] = 0;

    while(!q.empty()){
        auto t = q.front(); q.pop();

        for(int i=0; i<8; i++){
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];

            if(nx >=1 && nx<=N && ny>=1 && ny<=N && dis[nx][ny]==1e9){
                dis[nx][ny] = dis[t.first][t.second] + 1;
                q.push({nx, ny});
            }
        }
    }
    return dis[Fx][Fy]==1e9 ? -1 : dis[Fx][Fy];
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
	}
}