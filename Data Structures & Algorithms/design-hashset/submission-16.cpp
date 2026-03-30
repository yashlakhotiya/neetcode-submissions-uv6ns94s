struct TreeNode {
    int data;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int data) : data(data) {}
};

class BST {
    TreeNode *root = nullptr;
    TreeNode* insertNode(TreeNode *root, int data) {
        if(!root) return new TreeNode(data);
        if(data < root->data) root->left = insertNode(root->left, data);
        else if(data > root->data) root->right = insertNode(root->right, data);
        return root;
    }

    TreeNode* deleteNode(TreeNode *root, int data) {
        if(!root) return nullptr;
        if(data < root->data) root->left = deleteNode(root->left, data);
        else if(data > root->data) root->right = deleteNode(root->right, data);
        else {
            if(!root->left && !root->right) {
                delete root;
                root = nullptr;
                return root;
            } else if(root->left && !root->right) {
                TreeNode *temp = root;
                root = root->left;
                delete temp;
                return root;
            } else if(root->right && !root->left) {
                TreeNode *temp = root;
                root = root->right;
                delete temp;
                return root;
            } else {
                TreeNode *inorderSuccessorNode = inorderSuccessor(root->right);
                root->data = inorderSuccessorNode->data;
                root->right = deleteNode(root->right, inorderSuccessorNode->data);
                return root;
            }
        }
        return root;
    }

    TreeNode* inorderSuccessor(TreeNode *root) {
        TreeNode *curr = root;
        while(curr->left) {
            curr = curr->left;
        }
        return curr;
    }


    bool searchNode(TreeNode *root, int data) {
        if(!root) return false;
        if(data == root->data) return true;
        else if(data < root->data) return searchNode(root->left, data);
        else return searchNode(root->right, data);
    }

    public:
    void Insert(int key) {
        root = insertNode(root, key);
    }

    void Delete(int key) {
        root = deleteNode(root, key);
    }

    bool Search(int key) {
        return searchNode(root, key);
    }
};

class MyHashSet {
    vector<BST> slots;
    const int size = 10000;
    int hash(int data) {
        return data%size;
    }
public:
    MyHashSet() {
        slots.resize(size);
    }
    
    void add(int key) {
        int idx = hash(key);
        slots[idx].Insert(key);
    }
    
    void remove(int key) {
        int idx = hash(key);
        slots[idx].Delete(key);
    }
    
    bool contains(int key) {
        int idx = hash(key);
        return slots[idx].Search(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */