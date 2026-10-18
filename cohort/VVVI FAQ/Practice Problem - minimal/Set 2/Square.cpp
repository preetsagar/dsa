
#include <bits/stdc++.h>
using namespace std;

vector<long long> ds;

// Optimization:
// Instead of checking all 4! = 24 permutations, only 3 distinct vertex arrangements are enough (others are just rotations/reversals).
// The cleanest solution is to compute the 6 pairwise distances once, sort them, and verify: first 4 distances are equal and non-zero (sides), last 2 are equal (diagonals). This removes permutations entirely.

long long dist(vector<long long> a, vector<long long> b){
    long long dx = a[0]-b[0];
    long long dy = a[1]-b[1];

    return dx*dx + dy*dy;
}

bool isValidSquare(vector<vector<long long>> &v)
{
    long long AB = dist(v[0], v[1]);
    long long BC = dist(v[1], v[2]);
    long long CD = dist(v[2], v[3]);
    long long AD = dist(v[0], v[3]);
    long long AC = dist(v[0], v[2]);
    long long BD = dist(v[1], v[3]);

    vector<long long> dis = {AB, BC, CD, AD, AC, BD};
    sort(dis.begin(), dis.end());

    // for(int i:dis) cout<<i<<" "; cout<<"\n";

    if(dis[0] > 0 && (dis[0]==dis[1] && dis[1]==dis[2] && dis[2]==dis[3]) && dis[4]==dis[5]) return 1;
    else return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<long long>> v(4, vector<long long>(2));
    for (int i = 0; i < 4; i++)
        cin >> v[i][0] >> v[i][1];
    cout << isValidSquare(v) << '\n';
    return 0;
}
