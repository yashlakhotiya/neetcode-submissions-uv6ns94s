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
    int kthSmallest(TreeNode* root, int k) {
        int pos = 0;
        if(!root) return 0;
        stack<TreeNode*> s;
        auto curr = root;
        s.push(curr);
        while(curr || !s.empty()) {
            if(curr->left) {
                curr = curr->left; s.push(curr);
            }
            else {
                auto node = s.top(); s.pop();
                pos++;
                if(pos == k) return node->val;
                if(node->right) s.push(node->right);
            }
        }
        return 0;
    }
};
