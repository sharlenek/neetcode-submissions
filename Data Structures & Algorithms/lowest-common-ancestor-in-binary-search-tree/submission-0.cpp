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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr){
            return nullptr;
        }

        //do i need a while loop? when should it break
        //if p and q r on opposite sides of root, it should return root
        //else keep going until

        while (root !=nullptr){
            if (p->val > root->val && q->val > root->val){
                root = root->right;
            } else if (p->val < root->val && q->val < root->val){
                root = root->left;
            } else {
                return root;
            }
        }
        return root;

    }
};
