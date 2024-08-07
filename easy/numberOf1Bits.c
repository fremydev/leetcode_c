int hammingWeight(uint32_t n) {
    if (n == 0) {
        return 0;
    }
    int count = 0;
    while (n) {
        if (n & 1) {
            count++;
        }
        n >>= 1;
    }
    return count;
}
