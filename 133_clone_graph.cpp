#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<Node *, Node *> mpp;
    void dfs(Node *node, Node *clone_node)
    {
        for (auto n : node->neighbors)
        {
            if (mpp.find(n) == mpp.end())
            {
                Node *clone = new Node(n->val);
                mpp[n] = clone;
                clone_node->neighbors.push_back(clone);
                dfs(n, clone);
            }
            else
            {
                clone_node->neighbors.push_back(mpp[n]);
            }
        }
    }
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return NULL;
        Node *clone_node = new Node(node->val);
        mpp[node] = clone_node;
        dfs(node, clone_node);
        return clone_node;
    }
};