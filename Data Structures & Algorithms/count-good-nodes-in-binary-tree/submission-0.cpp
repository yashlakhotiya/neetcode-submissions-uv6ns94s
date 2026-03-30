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
    int goodNodes(TreeNode* root, int maxsofar) {
        if(!root) return 0;
        if(root->val >= maxsofar) {
            maxsofar = root->val;
            return 1+goodNodes(root->left,maxsofar)+goodNodes(root->right,maxsofar);
        } else {
            return goodNodes(root->left,maxsofar)+goodNodes(root->right,maxsofar);
        }
    }
public:
    int goodNodes(TreeNode* root) {
        return goodNodes(root, INT_MIN);
    }
};
