#include <stdio.h>

int main()
{   
    //char c[5] = {'3', '5', '*', '2', '+'};
    //char c[] = {'3', '5', '*', '2', '+'};
    char c[] = "35*2+";
    /*
    c[0] = '3';
    c[1] = '5';
    c[2] = '*';
    c[3] = '2';
    c[4] = '+';
    */
    int s[5];
    int sp = 0;
     
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
            s[sp]= c[i] - 48;
            sp = sp+1;
            printf("%d\n", s[sp-1]);
        }
        if (c[i] == '*'){
            //x = pop()
            sp = sp - 1;
            int m1 = s[sp];
            sp = sp -1;
            int m2 = s[sp];
            int r = m1 * m2;
            s[sp] = r;
            sp = sp + 1;
        }
        if (c[i] == '+'){
            //x = pop()
            sp = sp - 1;
            int m1 = s[sp];
            sp = sp -1;
            int m2 = s[sp];
            int r = m1 + m2;
            s[sp] = r;
            sp = sp + 1;
        }

    }
    printf("%d\n", s[sp - 1]);
    return 0;
}


