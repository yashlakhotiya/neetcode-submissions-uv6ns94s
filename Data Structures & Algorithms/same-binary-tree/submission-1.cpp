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
    bool isSameTreeIterative(TreeNode* n1, TreeNode* n2) {
        stack<pair<TreeNode*, TreeNode*>> s;
        s.push({n1,n2});
        while(!s.empty()) {
            auto [p,q] = s.top(); s.pop();
            if((p && !q) ||(!p && q)) return false;
            if((p && q) && p->val!=q->val) return false;
            if(p) s.push({p->left, q->left});
            if(q) s.push({p->right, q->right});
        }
        return true;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if(!p && !q) return true;
        // if((p && !q) ||(!p && q)) return false;
        // return (p->val==q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return isSameTreeIterative(p,q);
    }
};
