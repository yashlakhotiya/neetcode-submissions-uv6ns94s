struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

class BST {
    TreeNode *root;
    TreeNode* insertNode(TreeNode *root, int key) {
        if(!root) return new TreeNode(key);
        if(key < root->data) {
            root->left = insertNode(root->left, key);
        } else if(key > root->data) {
            root->right = insertNode(root->right, key);
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode *root, int key) {
        if(!root) return NULL;
        if(key < root->data) root->left = deleteNode(root->left, key);
        else if (key > root->data) root->right = deleteNode(root->right, key);
        else {
            if(!root->left && !root->right) {
                delete root;
                return NULL;
            } else if(!root->left && root->right) {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            } else if(!root->right && root->left) {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            } else {
                TreeNode *rightChildOfRoot = root->right;
                TreeNode *leftChildOfRoot = root->left;
                TreeNode *curr = leftChildOfRoot;
                TreeNode *prev = leftChildOfRoot;
                while(curr) {
                    prev = curr;
                    if(curr->right) curr = curr->right;
                    else if (curr->left) curr = curr->left;
                }
                prev->right = rightChildOfRoot;
                delete root;
                return leftChildOfRoot;
            }
        } 
    }

    bool search(TreeNode *root, int key) {
        if(!root) return false;
        if(root->data == key) return true;
        else if(key < root->data) return search(root->left, key);
        else return search(root->right, key);
    }

    public:
    BST() : root(nullptr)  {}

    void add(int key) {
        root = insertNode(root, key);
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    bool contains(int key) {
        return search(root, key);
    }
};

class MyHashSet {
    const int size = 10000;
    vector<BST> buckets;
    int hash(int key) {
        return key%buckets.size();
    }
public:
    MyHashSet() {
        buckets.resize(size);
    }
    
    void add(int key) {
        int idx = hash(key);
        if(!contains(key)) {
            buckets[idx].add(key);
        }
    }
    
    void remove(int key) {
        int idx = hash(key);
        buckets[idx].remove(key);
    }
    
    bool contains(int key) {
        int idx = hash(key);
        return buckets[idx].contains(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */