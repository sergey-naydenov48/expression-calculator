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
    int i;
    int n = sizeof(c) - 1;
    for (i = 0; i < n; ++i){
        printf("%c\n", c[i]);
    } 
 
    printf("Hello, World\n");
    return 0;
}


