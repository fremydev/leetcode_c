/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#pragma GCC optimize("O3", "unroll-loops")
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p == NULL && q == NULL)
        return true;
    if(p == NULL || q == NULL)
        return false;

    if(p->val != q->val)
        return false;

    bool left_branch = isSameTree(p->left, q->left);
    bool right_branch = isSameTree(p->right, q->right);

    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);

    return (left_branch && right_branch && left && right);
    
}
