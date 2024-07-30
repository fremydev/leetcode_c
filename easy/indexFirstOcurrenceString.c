int strStr(char* haystack, char* needle) {
    int i = 0, j = 0, n = 0, ini = 0;
    if(strlen(haystack)<strlen(needle))
    return -1;
    while (i < strlen(haystack)) {
        j = 0;
        n = strlen(needle);
        if (*(haystack + i) == *(needle)) {
            ini = i;
            while (i < strlen(haystack) && j < strlen(needle)) {
                if (*(haystack + i) == *(needle + j))
                    n--;
                i++;
                j++;
            }
            if (n == 0) {
                return ini;
            }
            i=ini;
        }
        i++;
    }
    return -1;
}
