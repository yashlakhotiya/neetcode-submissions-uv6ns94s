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
    void find(TreeNode* root, int &pos, int &ans, int k) {
        if(!root || ans != 1e9) return;
        find(root->left, pos, ans, k);
        pos++;
        if(pos == k) {
            ans = root->val; return;
        }
        find(root->right, pos, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int pos=0, ans=1e9;
        find(root, pos, ans, k);
        return ans;
    }
};
