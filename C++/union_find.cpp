#include<bits/stdc++.h>
using namespace std;

template<typename T=int>
struct unionFind{
    unordered_map<T, T> par;
    unordered_map<T, int> size;
    bool isParentExist(T item){
        return par.find(item) != par.end();
    }
    T Find(T a){
        if(!isParentExist(a)){
            par[a] = a;
            size[a] = 1;
            return a;
        }
        while(a != par[a]){
            a = par[a];
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
