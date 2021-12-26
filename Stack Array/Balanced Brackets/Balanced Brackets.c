// =================Shrook Ehab Attia - G1 - AI Nasr City=================
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef struct Stack{
    int top;
    char arr[MAX_SIZE];

}STACK;

void StackCreate(STACK *);
void StackPush(STACK *, char);
void StackPop(STACK *);
char StackTop(STACK *);
void PrintStackElements(STACK *);
int isFull(STACK *);
int isEmpty(STACK *);
void ReverseString(char *, int);
int BalancedBrackets(char *);

int main()
{
//    STACK st;
//
//    StackCreate(&st);
//
//    StackPush(&st, 10);
//    StackPush(&st, 20);
//    StackPush(&st, 30);
//    StackPush(&st, 40);
//    StackPush(&st, 50);
//
//    PrintStackElements(&st);
//    printf("\n=================================\n\n");
//
//    StackPop(&st);
//    StackPop(&st);
//
//    PrintStackElements(&st);
//    printf("\n=================================\n\n");
//
//    char arr[6] = "Shrook";
//    printf("NAME = %s\n", arr);
//    ReverseString(&arr, 6);
//    printf("NAME = %s\n", arr);

    char Brackets[MAX_SIZE];


    printf("Please Enter String : ");
    scanf("%s", &Brackets);
    printf("\n");


    if(BalancedBrackets(&Brackets))
        printf("Balanced Brackets :D\n");
    else
        printf("Not Balanced Brackets :(\n");



    return 0;
}

int BalancedBrackets(char *Brackets){
    STACK st;
    int i = 0;

    StackCreate(&st);

    while(Brackets[i] != '\0'){
        if(Brackets[i] == '{' || Brackets[i] == '[' || Brackets[i] == '(')
            StackPush(&st, Brackets[i]);

        else {
            if(!(isEmpty(&st))){
                if(Brackets[i] == '}'){
                    if(StackTop(&st) == '{')
                        StackPop(&st);
                    else
                        return 0;
                }

                else if(Brackets[i] == ')'){
                    if(StackTop(&st) == '(')
                        StackPop(&st);
                    else
                        return 0;
                }

                else if(Brackets[i] == ']'){
                    if(StackTop(&st) == '[')
                        StackPop(&st);
                    else
                        return 0;
                }

            }
            else
                return 0;
        }

        i++;
    }

    if(isEmpty(&st))
        return 1;
    else
        return 0;

}

void StackCreate(STACK *st){
    st->top = -1;
}

void StackPush(STACK *st, char item){
    if(isFull(&st))
        printf("The Stack is Full :(\n");

    else{
        st->top++;
        st->arr[st->top] = item;
    }
}

void StackPop(STACK *st){
    if(isEmpty(&st))
        printf("The Stack is Empty :(\n");
    else
        st->top--;
}

char StackTop(STACK *st){
    return st->arr[st->top];
}

void PrintStackElements(STACK *st){
    int top = st->top, i = 1;
    while (top != -1){
        printf("Element number (%d) : %c\n", i, st->arr[top]);
        top--;
        i++;
    }
}

int isFull(STACK *st){
    if(st->top == MAX_SIZE - 1)
        return 1;
    return 0;
}

int isEmpty(STACK *st){
    if(st->top == - 1)
        return 1;
    return 0;
}

void ReverseString(char *arr, int lenght){
    STACK st;
    int i;

    StackCreate(&st);

    for(i = 0; i < lenght; i++)
        StackPush(&st, arr[i]);

    for(i = 0; i < lenght; i++){
        arr[i] = StackTop(&st);
        StackPop(&st);
    }

}
