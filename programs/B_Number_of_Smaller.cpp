#include "bits/stdc++.h"
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    int i = 0, j = 0;
    while(j < m){
        if(i != n && a[i] < b[j]) i++;
        else{
            cout << i << " ";
            j++;
        }
    }
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

    