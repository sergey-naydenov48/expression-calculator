#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int s[5];
    int sp;
};

int st_pop(struct Stack *st)
{
    st->sp = st->sp - 1;
    if (st->sp < 0) {
        printf("Error: empty stack.\n");
        exit(1);
    }
    return st->s[st->sp];
}

void st_push(struct Stack *st, int v, int size)
{
    if (st->sp >= size) {
        printf("Error: full stack.\n");
        exit(1);
    }
    st->s[st->sp] = v;
    st->sp = st->sp + 1;
}

struct Calcres {
	int quantity;
	int result;
};


struct Calcres calculator(char c[]){
    int i;
    /*int s[5];*/
    //int sp = 0;
    struct Stack st;
    st.sp = 0;
    
    for (i = 0; c[i] != 0; ++i){
        if (c[i] >= '0' and c[i] <= '9') {
            st_push(&st, c[i] - 48, sizeof(st.s)/sizeof(st.s[0]));
            printf("%d\n", st.s[st.sp-1]);
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
            int m2 = st_pop(&st);
            int m1 = st_pop(&st);
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
            st_push(&st, r, sizeof(st.s)/sizeof(st.s[0]));
        }
    }
    struct Calcres RES;
    RES.quantity = st.sp;
    RES.result = st.s[st.sp-1];
    return RES;
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
    
    struct Calcres spp;
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
    
    spp = calculator(c);
    printf("result = %d, quantity = %d\n", spp.result, spp.quantity);
    return 0;
}


