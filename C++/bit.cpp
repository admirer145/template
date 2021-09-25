#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct bitTree{
    vector<T> bit;
    int size;

    bitTree(int n){
        size = n;
        bit.resize(n+1, 0);
    }

    void update(int indx, T val){
        while (indx <= size)
        {
            bit[indx] += val;
            indx += (indx & -indx);
        }
    }

    T sum(int indx){
        T res;
        while(indx > 0){
            res += bit[indx];
        }
        return res;
    }
    void debug(){
        cout<<"Items of bit are: ";
        for(auto item: bit){
            cout<<item<<" ";
        }
        cout<<"\n";
    }
};

void test(){
    bitTree<int> b(10);
    b.debug();
}

int main(){
    test();
    return 0;
}
