bool isValid(char* s) {
    int len = strlen(s);
    char stk[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') stk[++top] = s[i];
        else {
            if (top == -1) return false;
            if((s[i] == ')' && stk[top] != '(') || (s[i] == '}' && stk[top] != '{') || (s[i]== ']' && stk[top] != '['))
                return false;
            top--;
        }
    }
    return top == -1;
}
