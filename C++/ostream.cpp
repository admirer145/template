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

// No iterator is provided by stack so need to create the copy
template<typename T>
ostream& operator << (ostream &out, stack<T> st){
    while(!st.empty()){
        out << st.top() << " ";
        st.pop();
    }
    return out;
}

// No iterator is provided by queue so need to create the copy
template<typename T>
ostream& operator << (ostream &out, queue<T> q){
    while(!q.empty()){
        out << q.front() << " ";
        q.pop();
    }
    return out;
}

// No iterator is provided by queue so need to create the copy
template<typename T>
ostream& operator << (ostream &out, priority_queue<T> pq){
    while(!pq.empty()){
        out << pq.top() << " ";
        pq.pop();
    }
    return out;
}

// Support for custom hasher or min heap
template<typename T, typename V, typename H>
ostream& operator << (ostream &out, priority_queue<T, V, H> pq){
    while(!pq.empty()){
        out << pq.top() << " ";
        pq.pop();
    }
    return out;
}

template<typename T>
ostream& operator << (ostream &out, list<T> &l){
    for(auto val: l){
        out << val << " ";
    }
    return out;
}

////////////////////////////////// TEMPLATE END ////////////////////////////////////////

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

void test_unordered_map(){
    cout << "Test for unordered map\n";
    unordered_map<Node, int, NodeHasher> mp;
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            mp[{i, j}] = (i-1)*10 + j;
        }
    }
    cout << mp << "\n";
}

void test_priority_queue(){
    cout << "Test for priority queue\n";
    priority_queue<Node> st;
    st.push({1, 2});
    st.push({3, 1});
    st.push({2, 3});
    cout << st << "\n";
}

void test_list(){
    cout << "Test for linked list\n";
    list<Node> lst;
    lst.push_back({1,2});
    lst.push_back({3,2});
    lst.push_front({2,5});
    cout << lst << "\n";
}

void test(){
    test_unordered_map();
    test_priority_queue();
    test_list();
}

int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        test();
    }
    return 0;
}