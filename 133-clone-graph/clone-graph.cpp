/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }

        Node* cloneNode = new Node(node->val);
        unordered_map<Node*, Node*> mp;
        mp[node] = cloneNode;

        function<void(Node*,Node*)> dfs = [&](Node* u, Node* node) {

            for (Node* v : node->neighbors) {

                if (mp.find(v) != mp.end()) {
                    u->neighbors.push_back(mp[v]);

                } else {
                    Node* B = new Node(v->val);
                    u->neighbors.push_back(B);
                    mp[v] = B;
                    dfs(B, v);
                }
            }
        };

        dfs(cloneNode, node);

        return cloneNode;
    }
};