#define MAGIC 5000
bool containsDuplicate(int* nums, int numsSize) {
    uint64_t poormanhash[MAGIC] = {0};
    for (int i = 0; i < numsSize; i++) {
        int v = nums[i] +  1000000001;
        int mod = v % MAGIC;
        uint64_t loc = poormanhash[mod];
        if (loc != 0 && loc % v == 0) {
            return true;
        } if (loc == 0) {
            poormanhash[mod] = v;
        } else {
            poormanhash[mod] *= v;
        }
    }
    return false;
}
