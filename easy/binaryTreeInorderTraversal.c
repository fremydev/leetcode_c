/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#pragma GCC optimize("O3", "unroll-loops")
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
  int *res = malloc(sizeof(int ) * 100);
  struct  TreeNode* stack[100];
  int top = -1;
  struct TreeNode* curr = root;
  *returnSize= 0;
  while(curr != NULL || top != -1){
    while(curr != NULL)
    {
      stack[++top] = curr;
      curr = curr->left;
    }
    curr = stack[top--];
    res[(*returnSize)++] = curr->val;
    curr = curr->right;
  }
  return res;
}
