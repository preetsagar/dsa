#include <bits/stdc++.h>
using namespace std;

#define int long long

int arr[200020];
int t[800080];
int n,q;

void build(int index, int l, int r){
    if(l==r){
        t[index] = arr[l];
        return;
    }
    
    int mid = (l+r)/2;
    build(2*index, l, mid);
    build(2*index+1, mid+1, r);
}

void update(int index, int l, int r, int lq, int rq, int x){
    if(lq>r || rq<l) return;
    if(l>=lq && r<=rq){
        t[index] += x;
        return;
    }
    
    int mid = (l+r)/2;
    update(2*index, l, mid, lq, rq, x);
    update(2*index+1, mid+1, r, lq, rq, x);
}

int query(int index, int l, int r, int x){
    // cout<<"("<<index<<" : "<<l<<", "<<r<<", "<<x<<") ";
    if(x>r || x<l) return 0;
    if(l==r){
        return t[index];
    }
    
    
    int ans=0;
    int mid = (l+r)/2;
    if(x <= mid){
        return t[index] + query(2*index, l, mid, x);
    }
    else return t[index] + query(2*index+1, mid+1, r, x);
}



signed main()
{
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    build(1, 1, n);
    // for(int i=1; i<=15; i++){
    //     cout<<t[i]<<" ";
    // }
    // cout<<'\n';
    while(q--){
        int ch; cin>>ch;
        if(ch==1){
            int l,r,u;
            cin>>l>>r>>u;
            update(1, 1, n, l, r, u);
        }
        else{
            int k; cin>>k;
            cout<<query(1, 1, n, k)<<'\n';
        }
    }
    
    return 0;
}