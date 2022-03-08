#include<bits/stdc++.h>
using namespace std;

template<typename T=int>
struct unionFind{
    unordered_map<T, T> par;
    unordered_map<T, int> size;

    T Find(T a){
        if(par.find(a) == par.end()){
            par[a] = a;
            size[a] = 1;
            return a;
        }
        while(a != par[a]){
            a = par[a] = par[par[a]];
        }
        return a;
    }

    void Union(T a, T b){
        a = Find(a);
        b = Find(b);
        if(a == b){
            return;
        }
        if(size[a] < size[b]){
            swap(a, b);
        }
        size[a] += size[b];
        par[b] = a;
    }
};

// Much Faster without template, assuming nodes are from 0 to n-1
struct UnionFind{
    vector<int> par;
    vector<int> size;
    
    UnionFind(int n){
        par = vector<int>(n);
        size = vector<int>(n, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int node){
        while(node != par[node]){
            node = par[node] = par[par[node]];
        }
        return node;
    }

    bool combine(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v){
            return false;
        }
        if(size[u] < size[v]){
            swap(u, v);
        }
        par[v] = u;
        size[u] += size[v];
        return true;
    }
};

void test(){
    unionFind<char> uf;
    uf.Union('a', 'b');
    uf.Union('b', 'c');
    if(uf.Find('a') == uf.Find('c')){
        cout<<"Working\n";
    }else{
        cout<<"Something went wrong\n";
    }
}

int main(){
    test();
    return 0;
}
