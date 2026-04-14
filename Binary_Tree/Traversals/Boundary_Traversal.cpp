class Solution {
public:
    bool isLeaf(Node *root) {
        return !root->left && !root->right;
    }

    void addLeft(Node *root, vector<int> &res) {
        Node *curr = root->left;   // ✅ FIX

        while (curr) {
            if (!isLeaf(curr)) {
                res.push_back(curr->data);
            }

            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addLeaf(Node *root, vector<int> &res) {
        if (!root) return;

        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }

        if (root->left) addLeaf(root->left, res);
        if (root->right) addLeaf(root->right, res);
    }

    void addRight(Node *root, vector<int> &res) {
        Node *curr = root->right;   // ✅ FIX
        vector<int> temp;

        while (curr) {
            if (!isLeaf(curr)) {
                temp.push_back(curr->data);
            }

            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }

        // reverse
        for (int i = temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }

    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;

        if (!root) return res;   // ✅ FIX

        if (!isLeaf(root)) {
            res.push_back(root->data);
        }

        addLeft(root, res);
        addLeaf(root, res);
        addRight(root, res);

        return res;   // ✅ FIX
    }
};
