#include <stdio.h>
#include <stdlib.h>


int pop(int s[], int * p) 
{
    *p = *p - 1;
    if (*p < 0) {
        printf("Error: empty stack.\n");
        exit(1);
    }
    return s[*p];
}

void push(int s[], int * p, int v, int size) 
{
    if (*p >= size) {
        printf("Error: full stack.\n");
        exit(1);
    }
    s[*p] = v;
    *p = *p + 1;    
}

int main()
{   
    //char c[5] = {'3', '5', '*', '2', '+'};
    //char c[] = {'3', '5', '*', '2', '+'};
    char c[] = "37+";
    /*
    c[0] = '3';
    c[1] = '5';
    c[2] = '*';
    c[3] = '2';
    c[4] = '+';
    */
    int s[5];
    int sp = 0;
  
    int * SPadress;
    SPadress = &sp;
    /* *SPadress = 2; */
     
    int i;
    int n = sizeof(c) - 1;
    for (i = 0; i < n; ++i){
        printf("%c\n", c[i]);
    } 

    /* 
    // push(100)
    s[sp] = 100;
    sp = sp + 1;
    
    // x = pop()
    sp = sp - 1
    x = s[sp];
    */
    
    printf("Hello, World\n");
    
    for (i = 0; i < n; ++i){
        if (c[i] >= '0' and c[i] <= '9') {
            push(s, &sp, c[i] - 48, sizeof(s)/sizeof(s[0])); 
            printf("%d\n", s[sp-1]);
        }
        if (c[i] == '*' or c[i] == '+' or c[i] == '/' or c[i] == '-'){
            //x = pop()
            int r;
/*
            sp = sp - 1;
            if (sp < 0) {
                printf("Error: empty stack.\n");
                exit(1);
            }
            int m2 = s[sp];
*/
            int m2 = pop(s, &sp); 
            int m1 = pop(s, &sp);
            if (c[i] == '*') {
                r = m1 * m2;
            }
            else if (c[i] == '+') {
                r = m1 + m2;
            }
            else if (c[i] == '/') {
                r = m1 / m2;
            }
            else if (c[i] == '-') {
                r = m1 - m2;    
            }
            push(s, &sp, r, sizeof(s)/sizeof(s[0]));
        }
    }
    printf("result=%d\nsp=%d\n", s[sp - 1], sp);
    return 0;
}


