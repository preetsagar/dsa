
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> TransitiveClosureGraph(vector<vector<int>> adj)
{
	int n;
    n = adj.size();

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                adj[i][j] = adj[i][j] | (adj[i][k] & adj[k][j]);
            }
        }
    }

    return adj;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> adj(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> adj[i][j];
			if (i == j)
			{
				adj[i][j] = 1;
			}
		}
	}

	vector<vector<int>> T = TransitiveClosureGraph(adj);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << T[i][j] << ' ';
		}
		cout << '\n';
	}
}
