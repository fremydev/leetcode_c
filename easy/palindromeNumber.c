bool isPalindrome(int x) {
    int original=x;
    int num;
    long long reversed=0;
    while(x>0){
        num=x%10;

        reversed = reversed*10+num;
        x/=10;
    }
    return original==reversed;
}
