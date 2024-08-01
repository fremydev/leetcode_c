#pragma GCC optimize("O3", "unroll-loops")
int minDepth(struct TreeNode* root) {
    if (root == NULL) return 0;

    struct TreeNode* queue[8000]; 
    uint16_t front = 0, rear = 0;
    uint16_t depth = 1;
    queue[rear++] = root;

    while (front<rear){
        uint16_t tmp = rear - front;
        for (uint16_t i = 0; i < tmp; i++){
            struct TreeNode* tmp_node = queue[front++];
            if (tmp_node->left == NULL && tmp_node->right == NULL){
                return depth;
            }
            if (tmp_node->left != NULL){
                queue[rear++] = tmp_node->left;
            }
            if (tmp_node->right != NULL){
                queue[rear++] = tmp_node->right;
            }
        }
        depth++;
    }
    return depth;
}
