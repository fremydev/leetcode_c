/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* result=(int*)malloc((digitsSize+1)*sizeof(int));
    int c=1;
    int sum=0;
    for(int i = digitsSize-1;i>=0;i--){
        sum=digits[i]+c;
        result[i+1] = sum%10;
        c=sum/10;
    }

    if(c){
        result[0]=c;
        *returnSize=digitsSize+1;
    }
    else{
        result++;
        *returnSize = digitsSize;
    }
    return result;
}
