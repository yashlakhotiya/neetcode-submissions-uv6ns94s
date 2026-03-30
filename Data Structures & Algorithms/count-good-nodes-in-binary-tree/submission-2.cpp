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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, INT_MIN});
        int res=0;
        while(!q.empty()) {
            auto [node, maxsofar] = q.front(); q.pop();
            int goodnode = maxsofar<=node->val?1:0;
            maxsofar=max(maxsofar, node->val);
            res += goodnode;
            if(node->left) q.push({node->left, maxsofar});
            if(node->right) q.push({node->right, maxsofar});
        }
        return res;
    }
};
