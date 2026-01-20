class Solution {
public:
    Node* flattenBST(Node* root) {
        if (root == NULL) return NULL;

        // flatten left and right subtrees
        Node* leftHead  = flattenBST(root->left);
        Node* rightHead = flattenBST(root->right);

        // disconnect left
        root->left = NULL;

        // attach left list to root
        if (leftHead != NULL) {
            Node* temp = leftHead;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            temp->right = root;
        }

        // attach right list
        root->right = rightHead;

        // return correct head
        return (leftHead != NULL) ? leftHead : root;
    }
};
