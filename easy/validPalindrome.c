#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char * s){
    int len = strlen(s);
    char cleaned[len+1]; // Array to store cleaned characters
    int index = 0;

    // Clean the string: remove non-alphanumeric characters and convert to lowercase
    for (int i = 0; i < len; i++) {
        if (isalnum(s[i])) {
            cleaned[index++] = tolower(s[i]);
        }
    }
    cleaned[index] = '\0'; // Null terminate the cleaned string

    // Check if the cleaned string is a palindrome
    int left = 0;
    int right = index - 1;
    while (left < right) {
        if (cleaned[left] != cleaned[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
