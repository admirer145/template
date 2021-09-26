#include<bits/stdc++.h>
using namespace std;

template<typename K, typename V>
struct bitTree{
    unordered_map<K, V> bit;
    V lim;
    bitTree(V size){
        lim = size;
    }

    void update(K indx, V val){
        while (indx < lim){
            bit[indx] += val;
            indx += (indx & -indx);
        }
    }

    V query(K indx){
        V res = 0;
        while(indx > 0){
            res += bit[indx];
            indx -= (indx & -indx);
        }
        return res;
    }

    V query(K l, K r){
        return query(r) - query(l-1);
    }
};

void test(){
    bitTree<int, int> b(20);
    vector<int> arr = {1, 2, 3, 5, 8, 10};
    for(int i=0; i<arr.size(); i++){
        b.update(i+1, arr[i]);
    }
    if(b.query(3, 5) == 16){
        cout<<"Working\n";
    }else{
        cout<<"Something goes wrong\n";
    }
}

int main(){
    test();
    return 0;
}
