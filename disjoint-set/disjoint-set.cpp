#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent;
    public:
        DisjointSet(int n){
            parent.resize(n + 1);
            rank.resize(n + 1, 0); // rank[u] -> Depth of the tree from u
            for(int i = 1; i <= n; i++) parent[i] = i; // Initially, parent[u] = u
        }

        // Maintain ultimate parent
        int findPar(int u){
            if(parent[u] == u) return u;
            return parent[u] = findPar(parent[u]);
        }

        void unionByRank(int u, int v){
            int ulp_u = findPar(u), ulp_v = findPar(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] > rank[ulp_v]) parent[ulp_v] = ulp_u;
            else if(rank[ulp_v] > rank[ulp_u]) parent[ulp_u] = ulp_v;
            else{
                parent[ulp_v] = u;
                rank[ulp_u]++;
            }
        }

        int isSameComponent(int u, int v){
            return findPar(u) == findPar(v);
        }
};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    cout << ds.isSameComponent(3, 7) << endl;
    ds.unionByRank(3, 7);
    cout << ds.isSameComponent(3, 7) << endl;
}