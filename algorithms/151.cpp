void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

char * reverseWords(char * s){
    int len = strlen(s);
    for (int i = 0; 2 * i < len; ++i)
        swap(s + i, s + (len - 1 - i));
    char *p = s;
    char *q = s;
    char *cur = s;
    while (*p != '\0' && *q != '\0') {
        while (*p != '\0' && *p == ' ')
            ++p;
        q = p;
        while (*q != '\0' && *q != ' ')
            ++q;
        if (p >= q) 
            continue;
        if (cur != s) {
            *cur = ' ';
            ++cur;
        }
        char *tmp = cur;
        while (p < q) {
            *tmp = *p;
            ++tmp;
            ++p;
        }
        char *beg = cur;
        cur = tmp;
        --tmp;
        while (beg < tmp) {
            swap(beg, tmp);
            ++beg;
            --tmp;
        }
    }
    *cur = '\0';
    return s;
}