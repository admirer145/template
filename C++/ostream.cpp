#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second

template<typename K, typename V>
ostream& operator << (ostream &out, pair<K, V> &pr){
    out << "(" << pr.first << ", " << pr.second << ")";
    return out;
}

template<typename T>
ostream& operator << (ostream &out, vector<T> &arr){
    out << "{ ";
    for(auto val: arr){
        out << val << " ";
    }
    out << "}";
    return out;
}

template<typename T>
ostream& operator << (ostream &out, vector<vector<T>> &arr){
    for(auto val: arr){
        out << val << "\n";
    }
    return out;
}

template<typename K, typename V>
ostream& operator << (ostream &out, unordered_map<K, V> &mp){
    for(auto val: mp){
        out << "[" << val.first << " : " << val.second << "]\n";
    }
    return out;
}

struct Node{
    int key;
    int value;
    friend ostream& operator << (ostream &out, const Node &node){
        out << "(" << node.key << " " << node.value << ")";
        return out;
    }
};

void test(){
    vector<Node> arr = {{1, 2}, {4, 3}, {10, 20}};
    cout << arr << "\n";
}

int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        test();
    }
    return 0;
}