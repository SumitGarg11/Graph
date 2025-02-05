// Definition for a Node.
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> mpp; // To store mapping of original node to cloned node
    
    void dfs(Node* node, Node* clone_node) {
        for (auto n : node->neighbors) {
            if (mpp.find(n) == mpp.end()) { // If not already cloned
                Node* clone = new Node(n->val);
                mpp[n] = clone; // Store the cloned node
                clone_node->neighbors.push_back(clone);
                dfs(n, clone); // Recur for neighbors
            } else {
                clone_node->neighbors.push_back(mpp[n]); // Already cloned, just connect
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        Node* clone_node = new Node(node->val);
        mpp[node] = clone_node;
        dfs(node, clone_node);
        return clone_node;
    }
};
