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
    TreeNode* buildTree(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, unordered_map<int,int> &mp) {
        if(prestart > preend || instart > inend) return nullptr;
        TreeNode *root = new TreeNode(preorder[prestart]);
        int inrootindex = mp[root->val];
        int leftSideNoElements = inrootindex-instart;
        root->left = buildTree(preorder, prestart+1, prestart+leftSideNoElements, inorder, instart, inrootindex-1, mp);
        root->right = buildTree(preorder, prestart+leftSideNoElements+1, preend, inorder, inrootindex+1, inend, mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return buildTree(preorder,0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
    }
};
