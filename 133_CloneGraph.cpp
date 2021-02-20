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
        if(!node) return node;
        
        unordered_map<int, Node*> map;
        queue<Node*> q; // put those to deal with
        
        Node* nodeCopy = new Node(node->val, {});
        map[node->val] = nodeCopy;
        q.push(node);
        
        Node* cloneCur;
        while(!q.empty()){
            cloneCur = q.front();
            q.pop();
            
            for(auto n: cloneCur->neighbors){
                if(map.find(n->val) == map.end()){ // not found
                    map[n->val] = new Node(n->val, {});
                    q.push(n);
                }
                map[cloneCur->val]->neighbors.push_back(map[n->val]);
            }
        }
        
        return nodeCopy;
    }
};

// others' DFS:
/*
unordered_map<Node*, Node*> copies;
Node* cloneGraph(Node* node) {
    if (!node) {
        return NULL;
    }
    if (copies.find(node) == copies.end()) {
        copies[node] = new Node(node -> val, {});
        for (Node* neighbor : node -> neighbors) {
            copies[node] -> neighbors.push_back(cloneGraph(neighbor));
        }
    }
    return copies[node];
}*/