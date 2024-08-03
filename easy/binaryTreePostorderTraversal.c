#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Helper function to perform postorder traversal and store the values in the array.
 */
#pragma GCC optmize("O3", "unroll-loops")
void postorder(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;

    postorder(root->left, arr, index);
    postorder(root->right, arr, index);

    arr[(*index)++] = root->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    // Count the number of nodes to allocate the array.
    int count = 0;
    void countNodes(struct TreeNode* node) {
        if (node == NULL) return;
        count++;
        countNodes(node->left);
        countNodes(node->right);
    }
    
    countNodes(root);
    
    // Allocate the array to store the postorder traversal.
    int* result = (int*)malloc(count * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL; // Memory allocation failed.
    }

    // Initialize the returnSize and index.
    *returnSize = 0;
    int index = 0;
    
    // Perform postorder traversal and fill the array.
    postorder(root, result, &index);
    
    *returnSize = index;
    return result;
}
