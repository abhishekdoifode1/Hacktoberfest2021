#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int *container;
    int top;
};

int isOverflow(struct stack st){
    if(st.top == st.size -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct stack st){
    if(st.top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

struct stack push(struct stack st,int data){
    int chk = isOverflow(st);

    if(chk == 1){
        printf("STACK OVERFLOW\n");
    }
    else{
        st.top += 1;
        st.container[st.top] = data;
        printf("%d is pushed\n",st.container[st.top]);
    }

    return st;
}

struct stack pop(struct stack st){
    int chk = isEmpty(st);

    if(chk == 1){
        printf("STACK EMPTY\n");
    }
    else{
        printf("%d is popped\n",st.container[st.top]);
        st.top -= 1;
    }

    return st;
}

void top(struct stack st){
    int chk = isEmpty(st);

    if(chk == 1){
        printf("STACK EMPTY\n");
    }
    else{
        printf("%d\n",st.container[st.top]);
    }
}

int main(){
    struct stack stk;

    stk.size = 10;
    stk.top = -1;
    stk.container = (int*)malloc(stk.size*sizeof(int));

    top(stk);
    stk = push(stk,5);
    stk = push(stk,10);
    stk = push(stk,15);
    top(stk);
    stk = pop(stk);
    top(stk);
}

//done by Rupak Biswas