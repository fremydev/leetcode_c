int titleToNumber(char* columnTitle) {
    int n=0;
        for (int i=0;i<strlen(columnTitle);i++){
            n+=columnTitle[i]-64;
            if (i+1<strlen(columnTitle))
                n*=26;

        }
        return n;
}
