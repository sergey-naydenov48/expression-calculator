#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int s[5];
    int sp;
};

int isemptystack(struct Stack *st){
    return st->sp == 0;
}

int st_pop(struct Stack *st){
    if (isemptystack(st)){
        printf("Error: empty stack.\n");
        exit(1);
    }
    st->sp = st->sp - 1;
    return st->s[st->sp];
}

void st_push(struct Stack *st, int v)
{
    if (st->sp >= sizeof(st->s)/sizeof(st->s[0])) {
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
    // "  134  2 +" -> [i:1, i:2, o:+]
    
    char c = wg->d[wg->i];
    struct word r;
    if (0 <= c - 48 && c - 48 <= 9){
        r.nind = 1;
        int x = 0;
        
        while (0 <= c - 48 && c - 48 <= 9){
            int d = c - 48;
            x = x*10 + d;
            wg->i ++;
            c = wg->d[wg->i];
        }
        
        r.number = x;
    }
    else if ( c == '+' || c == '-' ||
              c == '*' || c == '/' || c =='(' || c ==')'){
         r.nind = 0;
         r.operation = c;
         wg->i ++;
    }
    else if ( c == ' '){
        while ( c == ' '){
            wg->i ++;
            c = wg->d[wg->i];
        }
        r = get_word(wg);    
    }
    else {
        r.nind = -1;
    }
    
    return r;
}

int isarithoper(char symbol){
    return symbol == '*' || symbol == '+' || symbol == '/' || symbol == '-';
}

int oper_prio(char symbol){
    if(symbol == '*' || symbol == '/')
        return 2;
    if(symbol == '+'|| symbol == '-')
        return 1;
    if(symbol == '(')
        return 0;        
    return -1;
}

int Deikstra(char c[]){
    struct word_grinder wg;
    wg.i = 0;
    wg.d = c;
    int counter = 0;
    struct Stack st;
    st.sp = 0;
    while (1) {
        struct word w;
        w = get_word(&wg);
        if (w.nind == -1){
            while (!isemptystack(&st)){
                int r;
                r = st_pop(&st);
                printf("%c ", r);
                counter = counter + 1;
            }
            break;
        }
        
        if (w.nind == 1){
            printf("%d ", w.number);
            counter = counter + 1;
        }
        
        if (w.nind == 0 && isarithoper(w.operation)){
            while (!isemptystack(&st)){
                int r;
                r = st_pop(&st);
                if (oper_prio(w.operation) <= oper_prio(r)){
                    printf("%c ", r);
                    counter++;
                }
                else{
                    st_push(&st, r);
                    break;
                }
            }
            st_push(&st, w.operation);   
        }
        
        if (w.nind == 0 && w.operation == '('){
            st_push(&st, '(');
             
        }
        
        if (w.nind == 0 && w.operation == ')'){
            while(!isemptystack(&st)){
                int r;
                r = st_pop(&st);
                if (r == '('){
                    break;
                }
                printf("%c ", r);
                counter = counter + 1;
            }
        }
    }
    printf("\n");
    return counter;
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
            st_push(&st, w.number);
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
            st_push(&st, r);
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
    char c[] = "  111 2 +";
    /*
    c[0] = '3';
    c[1] = '5';
    c[2] = '*';
    c[3] = '2';
    c[4] = '+';
    */
    char a[] = "123";
    int x = 0;
    
    for (int i = 0; a[i]; ++i){
        int d = a[i] - 48;
        x = x*10 + d;   
    }
    
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
    printf("%d\n", x);
    
    int r = Deikstra("(2+3)*4"); // 2 3 + 4 *
    printf("outuput length: %d\n", r);
    r = Deikstra("2+3*4"); // 2 3 4 * +     
    printf("outuput length: %d\n", r);
    r = Deikstra("2+3-4"); // 2 3 + 4 -     
    printf("outuput length: %d\n", r);
    return 0;
}


