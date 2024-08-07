#pragma GCC optmize("O3", "unroll-loops")
char *convertToTitle(int columnNumber) {
    int n = columnNumber;
    // Compute the length for the string
    int len = (n <= 26) ? 1 : ceil(log(n * 25.0 / 26 + 1) / log(26));    
    // Allocate memory for the string including the null-terminator
    char *ans = (char *)malloc((len + 1) * sizeof(char));
    ans[len] = '\0'; // Null-terminate the string
    
    while (n > 0) {
        n--;
        div_t x = div(n, 26);
        ans[--len] = (char)('A' + x.rem);
        n = x.quot;
    }
    return ans;
}
