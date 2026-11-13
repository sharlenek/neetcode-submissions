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
        if (node == nullptr){
            return nullptr;
        }

        unordered_map<Node*, Node*> copies;
        queue<Node*> nodestovisit;

        copies[node] = new Node(node->val);
        nodestovisit.push(node);

        while (!nodestovisit.empty()){
            Node* currnode = nodestovisit.front();
            nodestovisit.pop();

            for (int i = 0; i < currnode->neighbors.size(); ++i){
                Node* currneighbor = currnode->neighbors[i];

                if (copies.find(currneighbor) == copies.end()){
                    copies[currneighbor] = new Node(currneighbor->val);
                    nodestovisit.push(currneighbor);
                }

                copies[currnode]->neighbors.push_back(copies[currneighbor]);
            }
        }

        return copies[node];
        
    }
};
