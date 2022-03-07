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

// for custom hasher
template<typename K, typename V, typename Hasher>
ostream& operator << (ostream &out, unordered_map<K, V, Hasher> &mp){
    for(auto val: mp){
        out << val << " ";
    }
    return out;
}

template<typename K, typename V>
ostream& operator << (ostream &out, map<K, V> &mp){
    for(auto val: mp){
        out << "[" << val.first << " : " << val.second << "]\n";
    }
    return out;
}

template<typename T>
ostream& operator << (ostream &out, set<T> &s){
    for(auto val: s){
        out << val << " ";
    }
    return out;
}

template<typename T>
ostream& operator << (ostream &out, unordered_set<T> &s){
    for(auto val: s){
        out << val << " ";
    }
    return out;
}

// for custom hasher
template<typename T, typename Hasher>
ostream& operator << (ostream &out, unordered_set<T, Hasher> &s){
    for(auto val: s){
        out << val << " ";
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
    // for working with set
    bool operator < (const Node &other) const{
        if(key == other.key){
            return value < other.value;
        }
        return key < other.key;
    }
    // for working with unordered set
    bool operator == (const Node &other) const{
        return key == other.key && value == other.value;
    }
};

struct NodeHasher{
    size_t operator()(const Node &node) const{
        return std::hash<int>()(node.key) ^ (std::hash<int>()(node.value) << 1);
    }
};


void test(){
    unordered_map<Node, int, NodeHasher> mp;
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            mp[{i, j}] = (i-1)*10 + j;
        }
    }
    cout << mp << "\n";
}

int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        test();
    }
    return 0;
}