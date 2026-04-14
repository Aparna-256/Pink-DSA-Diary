class Solution {
public:
    vector<int> topView(Node *root) {
        vector<int> result;
        if (!root) return result;

        map<int, int> mp; // hd → node value
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            Node* node = front.first;
            int hd = front.second;

            // store first node at this HD
            if (mp.find(hd) == mp.end()) {
                mp[hd] = node->data;
            }

            if (node->left) {
                q.push({node->left, hd - 1});
            }

            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }

        // extract from map (sorted by HD)
        for (auto it : mp) {
            result.push_back(it.second);
        }

        return result;
    }
};
