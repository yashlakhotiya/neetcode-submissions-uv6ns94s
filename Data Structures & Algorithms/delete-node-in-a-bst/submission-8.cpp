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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        TreeNode* curr = root, *prev=nullptr;
        while(curr) {
            if(key < curr->val) {
                prev=curr;
                curr=curr->left;
            }
            else if(key > curr->val) {
                prev=curr;
                curr=curr->right;
            }
            else break;
        }
        if(!curr) return root;
        if(!curr->left && !curr->right) {
            if(prev){
                if(curr->val > prev->val) prev->right=nullptr;
                else prev->left=nullptr;
                return root;
            }
            return nullptr;
        }
        if(curr->left && !curr->right) {
            if(prev){
                if(curr->val > prev->val) prev->right = curr->left;
                else prev->left = curr->left;
                return root;
            }
            return curr->left;
        }
        if(curr->right && !curr->left) {
            if(prev){
                if(curr->val > prev->val) prev->right = curr->right;
                else prev->left = curr->right;
                return root;
            }
            return curr->right;
        }
        auto prevtemp = curr;
        auto temp = curr->right;
        while(temp->left) {
            prevtemp = temp;
            temp = temp->left;
        }
        if(temp->val > prevtemp->val) prevtemp->right = temp->right;
        else prevtemp->left = temp->right;
        curr->val = temp->val;
        return root;
    }
};