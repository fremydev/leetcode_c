/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#pragma GCC optimize("O3", "unroll-loops")
int sum=0, flag=0,target;
void traverse(struct TreeNode* root){
    if(root==NULL)
        return;
    if(sum==target && flag!=0)
          return;
    sum=sum+root->val;
    if(root->left==NULL && root->right==NULL){
        if(sum==target){
            flag++;
            return;
            }
        else{
            sum=sum-root->val;
            return;
      }
      }      
    traverse(root->left);
    traverse(root->right);
    sum=sum-root->val;
    return;
    }
bool hasPathSum(struct TreeNode* root, int targetSum) {
    flag=0,sum=0,target=targetSum;
    traverse(root);
    if(flag>0)
        return 1;
    else
        return 0;
}
