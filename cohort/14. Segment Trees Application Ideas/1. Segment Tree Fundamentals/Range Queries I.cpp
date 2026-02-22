#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,q;
int A[200020];
int t[800080];

void build(int index, int l, int r){
    if(l==r){
        t[index] = A[l]; 
        return;
    }

    int mid = (l+r)/2;
    build(2*index, l, mid);
    build(2*index+1, mid+1, r);

    t[index] = t[2*index] + t[2*index+1];
}

void update(int index, int l, int r, int i, int x){
    if(l==r){
        A[l] = x;
        t[index] = x;
        return;
    }

    int mid = (l+r)/2;

    if(i <= mid) update(2*index, l, mid, i, x);
    else update(2*index+1, mid+1, r, i, x);

    t[index] = t[2*index] + t[2*index+1];
}

int query(int index, int l, int r, int lq, int rq){
    if(r<lq || l>rq) return 0;
    if(l>=lq && r<=rq) return t[index];

    int mid = (l+r)/2;
    return query(2*index, l, mid, lq, rq) + query(2*index+1, mid+1, r, lq, rq);
}

signed main() {
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>A[i];
    }
    build(1, 1, n);
    while(q--){
        int a,b,c; cin>>a>>b>>c;
        if(a==1){
            update(1, 1, n, b, c);
        }
        else{
            cout<<query(1, 1, n, b, c)<<'\n';
        }
    }
    return 0;
}