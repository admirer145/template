#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct customVectorHasher{
    size_t operator()(const vector<T> arr) const{
        size_t res = arr.size();
        for(auto &item: arr){
            res ^= item + 0x9e3779b9 + (res<<6) + (res>>2);
        }
        return res;
    }
};

void test(){
    vector<int> v;
    unordered_map<vector<int>, int, customVectorHasher<int>> mp;
    mp[v] = 1;
    cout<<mp[v]<<"\n";
}

int main(){
    test();
    return 0;
}
