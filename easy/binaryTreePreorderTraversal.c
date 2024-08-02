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
#pragma GCC optmize("O3", "unroll-loops")
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
     if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Find the size of the binary tree
    int size = 0;
    struct TreeNode* stack[100]; // Use a stack to simulate recursion
    struct TreeNode* current = root;
    int top = -1;

    // Calculate the size of the tree
    while (current != NULL || top >= 0) {
        while (current != NULL) {
            size++;
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        current = current->right;
    }

    // Allocate memory for result array
    int* result = (int*)malloc(size * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Fill the result array with preorder traversal values
    current = root;
    top = -1;
    int index = 0;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            result[index++] = current->val;
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        current = current->right;
    }

    // Set the return size
    *returnSize = size;

    return result;
}
