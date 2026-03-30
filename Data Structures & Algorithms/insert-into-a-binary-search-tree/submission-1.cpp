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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        auto cur = root;
        TreeNode *prev=nullptr;
        while(cur) {
            prev=cur;
            if(val < cur->val) {
                cur=cur->left;
                if(!cur) {
                    prev->left = new TreeNode(val);
                }
            } else {
                cur=cur->right;
                if(!cur) {
                    prev->right = new TreeNode(val);
                }
            }
        }
        return root;
        
    }
};