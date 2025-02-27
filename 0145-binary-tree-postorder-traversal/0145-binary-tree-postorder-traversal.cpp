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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        stack<TreeNode*> st1;
        stack<int> st2;
        st1.push(root);
        
        while(!st1.empty()){
            TreeNode* currentNode = st1.top();
            st1.pop();
            st2.push(currentNode->val);
            if(currentNode->left != nullptr) st1.push(currentNode->left);
            if(currentNode->right != nullptr) st1.push(currentNode->right); 
        }

        while(!st2.empty()){
            ans.push_back(st2.top());
            st2.pop();
        }

        return ans;
    }
};