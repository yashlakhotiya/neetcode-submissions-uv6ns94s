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
    void findkthSmallest(TreeNode *root, int k) {
        if(!root) return;
        kthSmallest(root->left, k);
        pos++;
        if(pos == k) {
            ans=root->val;
            return;
        }
        kthSmallest(root->right, k);
    }
public:
    int pos = 0, ans = 0;
    int kthSmallest(TreeNode* root, int k) {
        findkthSmallest(root, k);
        return ans;
    }
};
