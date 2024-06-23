#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    long long n = 10000000;
    vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    while(t--){
        long long n;
        cin >> n;
        double s = sqrt(n);
        if(s == int(s)){
            if(is_prime[(int)(s)]){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            cout << "NO" << endl;
        }

    }
}