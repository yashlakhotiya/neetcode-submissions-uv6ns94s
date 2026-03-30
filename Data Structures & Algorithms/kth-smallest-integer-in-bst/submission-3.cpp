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
        while(curr || !s.empty()) {
            while(curr) {
                s.push(curr); curr = curr->left; 
            }
            
            curr = s.top(); s.pop();
            pos++;
            if(pos == k) return curr->val;
            curr = curr->right;
            
        }
        return 0;
    }
};
