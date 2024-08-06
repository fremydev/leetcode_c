#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isIsomorphic(char *s1, char *s2) {
    int map1[256] = {0};
    int map2[256] = {0};

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 != len2) {
        return false;
    }

    for (int i = 0; i < len1; i++) {
        char c1 = s1[i];
        char c2 = s2[i];

        // Check if there is a mismatch in mapping
        if (map1[(unsigned char)c1] != map2[(unsigned char)c2]) {
            return false;
        }

        // Establish the mapping
        map1[(unsigned char)c1] = i + 1; // use i + 1 to avoid zero value confusion
        map2[(unsigned char)c2] = i + 1;
    }
    return true;
}
