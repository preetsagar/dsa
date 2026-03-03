
#include <bits/stdc++.h>
using namespace std;


class SnapshotArray
{
    int len;
    map<int, vector<pair<int, int>>> arr;
    int snapID=0;
public:
	
	SnapshotArray(int length)
	{
		len = length;
        snapID=0;
	}

	void set(int index, int val)
	{
        if(arr[index].size()==0 || arr[index][arr[index].size()-1].first!=snapID){
            arr[index].push_back({snapID, val});
        }
        else{
            arr[index].back().second = val;
        }
	}

	int snap()
	{
        return snapID++;
	}

	int get(int index, int snap_id)
	{
		if(arr.find(index)==arr.end() || arr[index].size()==0) return 0; // This index was never set; default is 0.
		auto it = upper_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id, INT_MAX));
        if(it==arr[index].begin()) return 0;
		--it;
        return (*it).second;
	}
};


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int Q, L;
	cin >> Q >> L;

	SnapshotArray snapshotArray(L);

	while (Q--)
	{
		string op;
		cin >> op;

		if (op == "set")
		{
			int index, val;
			cin >> index >> val;

			snapshotArray.set(index, val);
		}
		else if (op == "get")
		{
			int index, snap_id;
			cin >> index >> snap_id;

			cout << snapshotArray.get(index, snap_id) << "\n";
		}
		else if (op == "snap")
		{
			cout << snapshotArray.snap() << "\n";
		}
	}

	return 0;
}
