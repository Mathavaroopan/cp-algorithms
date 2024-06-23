#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
using namespace std;

int a, b, c, pa, pb, pc, ca = 0, cb = 0, cc = 0, cost;

bool check(int mid){
    int have = cost;
    if(ca != 0 && a/ca < mid) have -= pa*(ca*mid - a);
    if(cb != 0 && b/cb < mid) have -= pb*(cb*mid - b);
    if(cc != 0 && c/cc < mid) have -= pc*(cc*mid - c);
    return have >= 0;
}

void solve(){
    string s;
    cin >> s;
    cin >> a >> b >> c >> pa >> pb >> pc >> cost;
    for(char i : s){
        if(i == 'B') ca++;
        else if(i == 'S') cb++;
        else cc++;
    }
    int low = 0, high = 1e15, ans = 0;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(check(mid)){
            ans = mid;
            low = mid + 1;
        }else high = mid - 1;
    }
    cout << ans << endl;
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}

