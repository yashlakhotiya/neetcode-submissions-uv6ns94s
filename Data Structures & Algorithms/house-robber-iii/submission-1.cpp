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
    int rob(TreeNode *root, bool pickedParent, vector<unordered_map<TreeNode*, int>> &dp) {
        if(dp[pickedParent].count(root)) return dp[pickedParent][root];
        if(pickedParent) {
            return dp[pickedParent][root]=rob(root->left, false,dp)+rob(root->right, false,dp);
        } else {
            return dp[pickedParent][root]=max(root->val+rob(root->left,true,dp)+rob(root->right, true,dp), rob(root->left,false,dp)+rob(root->right, false,dp));
        }
    }
    int rob(TreeNode* root) {
        vector<unordered_map<TreeNode*, int>> dp(2);
        dp[0][nullptr]=0, dp[1][nullptr]=0;
        return rob(root, false, dp);
    } 
};