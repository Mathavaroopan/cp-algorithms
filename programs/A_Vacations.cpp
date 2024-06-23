#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int, int> mp;
    mp.insert({1, 20});
    auto it = mp.lower_bound(2);
    if(it == mp.end()) cout << "end" << endl;
}