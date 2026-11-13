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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr){
            return {};
        }

        //should i use a queue?
        //need to keep track of the levels
        vector<vector<int>> bfs;
        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()){
            int size = nodes.size();
            vector<int> currentlevel;

            for (int i = 0; i < size; ++i){
                TreeNode* currNode = nodes.front();
                nodes.pop();

                currentlevel.push_back(currNode->val);

                if (currNode->left != nullptr){
                    nodes.push(currNode->left);
                }
                if (currNode->right != nullptr){
                    nodes.push(currNode->right);
                }
            }
            bfs.push_back(currentlevel);
            
        }
        return bfs;

        
    }
};
