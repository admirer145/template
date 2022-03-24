#include<bits/stdc++.h>
using namespace std;

// custom struture for priority queue
struct Node{
    // currently we have 2 data members, we can have multiple if needed
    int cost;
    int node;
    // default constructor
    Node(){}
    // constructor for creating (cost, node) object
    Node(int _cost, int _node){
        this->cost = _cost;
        this->node = _node;
    }
    // overriding < for comparing 2 elements in heap (min heap implementation)
    bool operator<(const Node &other) const{
        return cost > other.cost;  // change > to < for max heap
    }
};

// dijkstra algorithm is used to find shortest path from single node to all other nodes
// shortest path can be min edges, min cost, min weight, shortest distance, ...
// dijkstra works only when edge cost are non-negative (edge_cost >= 0)
// If negative weight is there try using Bellman-Ford
// dijkstra works for both directed and undirected graph

vector<int> dijkstra(vector<vector<Node>> &graph, int src, int n){
    // as per default Node implementation, using priority queue for getting min weight edge at top
    priority_queue<Node> pq;
    // distance array to keep track of distance from src to all other nodes
    vector<int> dist(n, INT_MAX); // initially all nodes are unreachable from src, so mark them infinity or max value
    dist[src] = 0;  // src itself is at distance 0
    pq.push(Node(0, src));  // initially only source is pushed to the heap with distance 0
    while(!pq.empty()){
        Node parent = pq.top(); // get the top node from the priority queue
        pq.pop(); // remove it from the priority queue

        // if some node is already processed with lower weight then don't process it again (stale data)
        if(parent.cost != dist[parent.node]){
            continue;
        }

        // iterating over all child from current node
        for(auto child: graph[parent.node]){
            // moving from parent node to the child node gives less cost then use this cost for the child node
            if(dist[parent.node] + child.cost < dist[child.node]){  // dist[parent.node] is min cost of parent + child.cost is the edge cost
                dist[child.node] = dist[parent.node] + child.cost;
                pq.push({dist[child.node], child.node}); // push the child and its cost into the pq
            }
        }
    }
    
    // mark unreachable nodes distance as -1 (If not needed comment below)
    for(auto &val: dist){
        if(val == INT_MAX){
            val = -1;
        }
    }

    return dist;
}
// someone can argue that since we are not using any visited array, is there a possibility that this while loops runs infinitely
// the answer is very simple: NO, since if we look closer to the code, where we are pushing the child into pq, there if condition
// will fail if it don't find any other shorter path because of the < operator, basically we are pushing the child into priority queue only 
// when there is some min path, that's the main reason why negative edge cost will not work (It runs infinitely since the edge cost keeps reducing)


void test(){
    // let number of nodes in graph is 5
    int n = 5;
    // create some edges in graph, inner vector representation is [from, to, cost]
    vector<vector<int>> edges = {{0, 1, 5}, {1, 2, 3}, {2, 3, 7}, {3, 0, 2}};
    //    0 - 3   5
    //   /   /
    //  1 - 2
    vector<vector<Node>> graph(n); // adjacency representation of a graph
    // inserting all edges into the graph
    for(auto e: edges){
        // creating an undirected graph
        graph[e[0]].push_back(Node(e[2], e[1]));
        graph[e[1]].push_back(Node(e[2], e[0]));
    }
    int src = 0;
    // call dijkstra which will return minimum cost from src to all other
    vector<int> resp = dijkstra(graph, src, n);
    if(resp[0]==0 && resp[1]==5 && resp[2]==8 && resp[3]==2 && resp[4]==-1){
        cout << "Working fine\n";
    }else{
        cout << "Something wrong happened, costs are [";
        for(auto cost: resp){
            cout << cost << " ";
        }
        cout << "]\n";
    }
}

int main(){
    int t = 1;
    // cin>>t;
    while(t--){
        test();
    }
    return 0;
}
