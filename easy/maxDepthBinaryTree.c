/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#pragma GCC optimize("O3", "unroll-loops")
int maxDepth(struct TreeNode* root) {
    int leftheight, rightheight;

    if(root == NULL)
        return 0;
    else {
        leftheight = maxDepth(root->left);
        rightheight = maxDepth(root->right);

        if (leftheight > rightheight) 
            return leftheight + 1;
        else
            return rightheight + 1;
    }
}
