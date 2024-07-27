#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
    int is_set;  // Flag to indicate if the entry is set
} HashTableEntry;

int hashFunction(int key, int size) {
    return (key % size + size) % size;  // Handle negative keys
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int hashTableSize = numsSize * 2;  // Double the size to reduce collisions
    HashTableEntry* hashTable = (HashTableEntry*)calloc(hashTableSize, sizeof(HashTableEntry));
    if (hashTable == NULL) {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int index = hashFunction(complement, hashTableSize);

        // Linear probing for collision resolution
        while (hashTable[index].is_set) {
            if (hashTable[index].key == complement) {
                int* result = (int*)malloc(sizeof(int) * 2);
                result[0] = hashTable[index].value;
                result[1] = i;
                *returnSize = 2;
                free(hashTable);
                return result;
            }
            index = (index + 1) % hashTableSize;
        }

        index = hashFunction(nums[i], hashTableSize);
        while (hashTable[index].is_set) {
            index = (index + 1) % hashTableSize;
        }

        hashTable[index].key = nums[i];
        hashTable[index].value = i;
        hashTable[index].is_set = 1;
    }

    *returnSize = 0;
    free(hashTable);
    return NULL;
}
