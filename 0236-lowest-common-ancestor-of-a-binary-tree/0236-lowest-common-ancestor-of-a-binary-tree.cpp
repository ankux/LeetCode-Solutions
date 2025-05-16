class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;

        // If the current node is either p or q, we return the current node
        // because one of the target nodes has been found
        if(root == p || root == q) {
            return root;
        }

        // Recur for the left and right subtrees
        TreeNode* left  = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are non-NULL, it means p and q are found
        // in different subtrees, so the current node is their LCA
        if(left != NULL && right != NULL) {
            return root;
        } 

        // If one of the left or right is non-NULL, return the non-NULL node
        // which means either p or q is found in that subtree
        if(left != NULL)
            return left;
        
        return right;
    }
};