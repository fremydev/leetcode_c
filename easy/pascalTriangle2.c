/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#pragma GCC optmize("O3", "unroll-loops")
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* row = (int*)malloc((*returnSize) * sizeof(int));

    if (row == NULL) {
        return NULL; // Return NULL if malloc fails
    }

    row[0] = 1;

    for (int i = 1; i <= rowIndex; i++) {
        row[i] = 1;
        for (int j = i - 1; j > 0; j--) {
            row[j] = row[j] + row[j - 1];
        }
    }

    return row;
}
