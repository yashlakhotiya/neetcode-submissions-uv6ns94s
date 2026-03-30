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
    bool isSameTreeIterativeBfs(TreeNode* n1, TreeNode* n2) {
        queue<pair<TreeNode*, TreeNode*>> qu;
        qu.push({n1,n2});
        while(!qu.empty()) {
            int size = qu.size();
            // for(int i=0; i<size; i++) {
                auto [p,q] = qu.front(); qu.pop();
                if((p && !q) ||(!p && q)) return false;
                if((p && q) && p->val!=q->val) return false;
                if(p && q) {
                    qu.push({p->left, q->left});
                    qu.push({p->right, q->right});
                }
            // }
        }
        return true;
    }

    bool isSameTreeIterativeDfs(TreeNode* n1, TreeNode* n2) {
        stack<pair<TreeNode*, TreeNode*>> s;
        s.push({n1,n2});
        while(!s.empty()) {
            auto [p,q] = s.top(); s.pop();
            if((p && !q) ||(!p && q)) return false;
            if((p && q) && p->val!=q->val) return false;
            if(p && q) {
                s.push({p->left, q->left});
                s.push({p->right, q->right});
            }
        }
        return true;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if(!p && !q) return true;
        // if((p && !q) ||(!p && q)) return false;
        // return (p->val==q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return isSameTreeIterativeDfs(p,q);
    }
};
