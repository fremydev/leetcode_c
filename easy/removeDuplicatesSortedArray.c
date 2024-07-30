int removeDuplicates(int* nums, int numsSize) {
    int k = 1;
    int i = 1;
    while(i < numsSize){
        if (nums[i] != nums[i - 1]){
            nums[k] = nums[i];
            k++;
        }
        i++;
    }

    return k;
}
