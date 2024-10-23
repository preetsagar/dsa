#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    stack<pair<string,int>> st;
    int i=0;
    int n=s.size();


    while(i<n) {
        if(s[i]=='(') {
            st.push({"(",-1});
            i++;
        }
        else if(s[i]==')'){
            int num=0;
            i++;
            while(i<n&&isdigit(s[i])) {
                num=(num*10)+(s[i]-'0');
                i++;
            }
            num=num==0?1:num;

            vector<pair<string,int>> tmp;
            while(true){
                auto tt=st.top(); st.pop();
                if(tt.first=="(") break;
                tmp.push_back({tt.first,tt.second*num});
            }

            for(auto ele:tmp){
                st.push(ele);
            }
        }
        else { // handling alphabets
            string curr="";
            curr.push_back(s[i]);i++;
            while(i<n&&islower(s[i])) {
                curr.push_back(s[i]);
                i++;
            }
            int num=0;
            while(i<n&&isdigit(s[i])) {
                num=(num*10)+(s[i]-'0');
                i++;
            }
            num=num==0?1:num;
            st.push({curr,num});
        }
    }

    map<string,int> _map;
    while(!st.empty()){
        auto it=st.top(); st.pop();
        _map[it.first]+=it.second;
    }

    for(auto& ele:_map) {
        cout<<ele.first;
        if(ele.second!=1) cout<<ele.second;
    }

    return 0;
}