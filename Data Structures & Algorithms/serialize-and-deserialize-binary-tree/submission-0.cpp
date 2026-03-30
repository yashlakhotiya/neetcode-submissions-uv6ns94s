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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root) return "";
        string res = "";
        q.push(root);
        while(!q.empty()) {
            auto node = q.front(); q.pop();
            if(node) res += to_string(node->val)+",";
            else res += "N,";
            if(node) q.push(node->left);
            if(node) q.push(node->right);
        }
        return res;
    }

    TreeNode* getNode(string s) {
        if(s == "") return nullptr;
        TreeNode *node = nullptr;
        if(s != "N") node = new TreeNode(stoi(s));
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return nullptr;
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        TreeNode* head = getNode(val);
        if(!head) return head;
        queue<TreeNode*> q;
        q.push(head);
        while(getline(ss, val, ',')) {
            auto node = q.front(); q.pop();
            node->left = getNode(val);
            getline(ss, val, ',');
            node->right = getNode(val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return head;
    }
};
