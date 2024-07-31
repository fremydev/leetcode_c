/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#pragma GCC optimize("O3", "unroll-loops")
bool check(struct TreeNode *left, struct TreeNode *right) {
    if (!left && !right) {
        return true;
    }
    if (!left || !right || left->val != right->val) {
        return false;
    }

    return check(left->left, right->right) && check(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (!root) return true;
    return check(root->left, root->right);
}
