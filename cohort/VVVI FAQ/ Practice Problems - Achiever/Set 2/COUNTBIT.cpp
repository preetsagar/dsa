
#include <bits/stdc++.h>
using namespace std;


int countSetBits(int n)
{
    n++;
    int ans = 0;
    for(int i=0; i<31; i++){
        int gpLen = 1<<(i+1);
        int noOfOnesInGp = 1<<i;
        int noOfZerosInGp = 1<<i;
        int completeSet = n/gpLen;

        ans += completeSet * noOfOnesInGp;

        int onesfromNonCompleteSet = max(0, (n%gpLen)- noOfZerosInGp);
        ans += onesfromNonCompleteSet;
    }

    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << countSetBits(n) << '\n';
    }

    return 0;
}
