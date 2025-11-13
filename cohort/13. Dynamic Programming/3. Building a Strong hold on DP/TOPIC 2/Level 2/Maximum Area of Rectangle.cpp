#include <bits/stdc++.h>
using namespace std;

int tc,n,m;
int mat[210][210];

int main() {
    cin>>tc; while(tc--){
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>mat[i][j];
            }
        }

        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i && mat[i][j]){
                    mat[i][j] = mat[i-1][j] + 1;
                }
            }
            // for(int j=0; j<m; j++) cout<<mat[i][j]<<" "; cout<<'\n';

            // Next Smaller Element
            vector<int> nextSmaller(m, 0);
            {
                stack<int> stk;
                for(int j=m-1; j>=0; j--){
                    while(!stk.empty() && mat[i][stk.top()]>=mat[i][j]){
                        stk.pop();
                    }
                    if(stk.empty())nextSmaller[j] = m;
                    else nextSmaller[j] = stk.top();
                    stk.push(j);
                }
                // for(int j=0; j<m; j++) cout<<nextSmaller[j]<<" "; cout<<'\n';
            }
            
            // Prev Smaller Element
            vector<int> prevSmaller(m, 0);
            {
                stack<int> stk;
                for(int j=0; j<m; j++){
                    while(!stk.empty() && mat[i][stk.top()]>=mat[i][j]){
                        stk.pop();
                    }
                    if(stk.empty())prevSmaller[j] = -1;
                    else prevSmaller[j] = stk.top();
                    stk.push(j);
                }
                // for(int j=0; j<m; j++) cout<<prevSmaller[j]<<" "; cout<<'\n'<<'\n';
            }

            int localAns = 0;
            for(int j=0; j<m; j++){
                localAns = max(localAns, mat[i][j]*(nextSmaller[j]-prevSmaller[j]-1));
            }
            ans = max(ans, localAns);
        }
        cout<<ans<<'\n';
        
    }
    return 0;
}