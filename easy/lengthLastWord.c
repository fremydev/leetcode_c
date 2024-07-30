#pragma GCC optimize("O3", "unroll-loops")
int lengthOfLastWord(char* s) {
    char *token;
    token=strtok(s, " ");
    int len;
    do{
        len=strlen(token);
    }while (token=strtok(NULL, " "));

    return len;
}
