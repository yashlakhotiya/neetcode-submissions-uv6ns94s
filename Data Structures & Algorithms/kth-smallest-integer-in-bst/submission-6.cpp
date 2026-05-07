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
    int find(TreeNode* root, int k, int &pos) {
        if(!root) return 1e9;
        int l = find(root->left, k, pos);
        if(l != 1e9) return l;
        pos++;
        if(pos == k) return root->val;
        int r = find(root->right, k, pos);
        return r;
    }
    int kthSmallest(TreeNode* root, int k) {
        int pos = 0;
        return find(root, k, pos);
    }
};
