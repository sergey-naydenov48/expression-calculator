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

struct word {
    int nind;
    char operation;
    int number;
};

struct word_grinder {
    char *d;
    int i;
};

struct word get_word(struct word_grinder* wg)
{
    char c = wg->d[wg->i];
    struct word r;
    if (0 <= c - 48 && c - 48 <= 9){
        r.nind = 1;
        r.number = c - 48;
        wg->i ++;
    }
    else if ( c == '+' || c == '-' ||
              c == '*' || c == '/' ){
         r.nind = 0;
         r.operation = c;
         wg->i ++;
    }
    else {
        r.nind = -1;
    }
    return r;
}

struct Calcres calculator(char c[]){
    int i;
    /*int s[5];*/
    //int sp = 0;
    struct Stack st;
    st.sp = 0;
    struct word_grinder wg;
    wg.i = 0;
    wg.d = c;
    while (1) {
        struct word w;
        w = get_word(&wg);
        if (w.nind == -1){
            break;
        }
        if (w.nind == 1){
            st_push(&st, w.number, sizeof(st.s)/sizeof(st.s[0]));
            printf("%d\n", st.s[st.sp-1]);
        }
        if (w.nind == 0){
            int r;
            int m2 = st_pop(&st);
            int m1 = st_pop(&st);
            if (w.operation == '*') {
                r = m1 * m2;
            }
            else if (w.operation == '+') {
                r = m1 + m2;
            }
            else if (w.operation == '/') {
                r = m1 / m2;
            }
            else if (w.operation == '-') {
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


