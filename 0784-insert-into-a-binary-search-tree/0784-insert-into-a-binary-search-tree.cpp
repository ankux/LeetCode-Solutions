class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if(!root) return newNode;

        TreeNode* temp = root;

        while(true) {
            if(val < temp->val) {
                if(!temp->left){
                    temp->left = newNode;
                    break;
                }
                temp = temp->left;
            } else {
                if(!temp->right){
                    temp->right = newNode;
                    break;
                }
                temp = temp->right;
            }
        }

        return root;
    }
};