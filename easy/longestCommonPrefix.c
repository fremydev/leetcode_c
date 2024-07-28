#include <stdio.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    char *str;

    while (k == 0) {
        i = 1;
        while (i < strsSize && strs[0][j] && strs[i][j]) {
            if (strs[0][j] == strs[i][j]) i ++;
            else break;
        }
        if (i == strsSize && strs[0][j] != '\0' && strs[i - 1][j] != '\0') j ++;
        else k ++;
        if (strs[m][j] == 0) k ++;
    }
    i = 0;
    str = malloc((j + 1) * sizeof(char));
    if (j == 0) {
        str[i] = 0;
        return (str);
    }
    if (j > 0) {
        while (i < j) {
            str[i] = strs[0][i];
            i ++;
        }
    }
    str[i] = 0;
    return (str);
}
