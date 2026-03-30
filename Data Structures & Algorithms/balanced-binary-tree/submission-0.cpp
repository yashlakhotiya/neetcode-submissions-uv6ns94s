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
    int balanced(TreeNode* root, bool &bal) {
        if(!root) return 0;
        int lh = balanced(root->left, bal);
        int rh = balanced(root->right, bal);
        if(bal && abs(rh-lh) > 1) bal=false;
        return 1+max(lh,rh);
    }
public:

    bool isBalanced(TreeNode* root) {
        bool res=true;
        balanced(root, res);
        return res;
    }
};
