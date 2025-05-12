class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Edge case: If the tree is empty, return an empty vector
        if (!root)
            return {};

        // Initialize the result vector to store levels
        vector<vector<int>> ans;

        // Use a queue for BFS traversal
        queue<TreeNode*> q;
        q.push(root);

        // Flag to track the direction (left-to-right or right-to-left)
        bool leftToRight = true;

        while (!q.empty()) {
            // Get the number of nodes at the current level
            int size = q.size();

            // Temporary vector to store nodes of the current level
            // Pre-allocate space for efficiency
            vector<int> temp(size);

            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();

                // Calculate the index where the current node's value should be
                // stored If leftToRight is true, use i (left-to-right order) If
                // false, use (size - 1 - i) (right-to-left order)
                int idx = leftToRight ? i : (size - 1 - i);
                temp[idx] = cur->val;

                // Add left and right children to the queue for the next level
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }

            // Add the current level's nodes to the result
            ans.push_back(temp);

            // Toggle the direction for the next level
            leftToRight = !leftToRight;
        }

        return ans;
    }
};