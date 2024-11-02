
#include <bits/stdc++.h>
using namespace std;


class AllOne
{
    map<string, int> m;
    multiset<pair<int, string>> mt;
public:

	AllOne() {}

	void inc(string key) {
		if(m.find(key)!=m.end()){
            mt.erase({m[key], key});
        }
        m[key]++;
        mt.insert({m[key], key});
	}

	void dec(string key) {
        if(m.find(key)!=m.end()){
            mt.erase({m[key], key});
        }
        m[key]--;
        if(m[key]==0) m.erase(key);
        else mt.insert({m[key], key});
	}

	string getMaxKey() {
        if(mt.empty()) return "";
        return (--mt.end())->second;
	}

	string getMinKey() {
		if(mt.empty()) return "";
        auto x = (*mt.begin());
        auto it = upper_bound(mt.begin(), mt.end(), make_pair(x.first+1, ""));
        it--;
        return it->second;
	}
};


int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int Q;
	cin >> Q;

	AllOne allOne;

	while (Q--)
	{
		string op;
		cin >> op;

		if (op == "inc") {
			string key;
			cin >> key;

			allOne.inc(key);
		}
		else if (op == "dec") {
			string key;
			cin >> key;

			allOne.dec(key);
		}
		else if (op == "getMaxKey") {
			cout << allOne.getMaxKey() << "\n";
		}
		else if (op == "getMinKey") {
			cout << allOne.getMinKey() << "\n";
		}
	}

	return 0;
}
