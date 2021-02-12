/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    struct Node{
        TreeNode* tn;
        bool visited;
    };
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        stack<Node> s;
        s.push({root, false});
        while(!s.empty()){
            // take out one element from stack
            Node node = s.top();      
            s.pop();
            
            if (node.visited)
            {
                cout << node.tn->val;
                ans.push_back(node.tn->val);
            }
            
            // find children
            if (node.tn->right != NULL) s.push({node.tn->right, false});
            s.push({node.tn->right, true}); // just record traversal to get to leaf first
            if (node.tn->left != NULL) s.push({node.tn->left, false}); 
            // now the left will be the top, so it will go to the left most leaf 
        }
        
        return ans;
    }
};