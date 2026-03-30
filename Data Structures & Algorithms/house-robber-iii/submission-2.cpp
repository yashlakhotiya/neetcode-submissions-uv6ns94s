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
    pair<int,int> dfs(TreeNode *root) {
        if(!root) return {0,0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int pick = root->val + left.second + right.second;
        int notpick = max(max(max(left.first+right.first, left.first+right.second), left.second+right.first), left.second+right.second);
        return {pick, notpick};
    }
    int rob(TreeNode* root) {
        auto p = dfs(root);
        return max(p.first, p.second);
    } 
};