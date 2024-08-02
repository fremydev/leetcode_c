#pragma GCC optmize("O3", "unroll-loops")
int singleNumber(int* nums, int numsSize){
    int uniqNum = 0;
    for (int i = 0; i < numsSize; i++) {
        uniqNum = uniqNum ^ nums[i];
    } return uniqNum; 
}
