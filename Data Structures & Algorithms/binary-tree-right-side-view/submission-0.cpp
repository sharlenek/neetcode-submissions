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
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr){
            return {};
        }

        vector<int> right;
        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()){
            int size = nodes.size();
            
            for (int i = 0; i < size; ++i){
                TreeNode* currnode = nodes.front();
                nodes.pop();

                if (i == size-1){
                    right.push_back(currnode->val);
                }

                if (currnode->left != nullptr){
                    nodes.push(currnode->left);
                }
                if (currnode->right != nullptr){
                    nodes.push(currnode->right);
                }
            }
        }
        return right;

        
    }
};
