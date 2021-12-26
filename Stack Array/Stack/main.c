#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef struct Stack{
    int top;
    int arr[MAX_SIZE];

}STACK;

void StackCreate(STACK *);
void StackPush(STACK *, int);
void StackPop(STACK *);
int StackTop(STACK *);
void PrintStackElements(STACK *);
int isFull(STACK *);
int isEmpty(STACK *);
//void ReverseString(char *, int);
//int BalancedBrackets(char *);
int StackMin(STACK );

int main()
{
    STACK st;

    StackCreate(&st);
    int num, minimumSt;

    printf("Please Enter the stack number 1 : ");
    scanf("%d", &num);
    StackPush(&st, num);
    printf("\n");

    printf("Please Enter the stack number 2 : ");
    scanf("%d", &num);
    StackPush(&st, num);
    printf("\n");

    printf("Please Enter the stack number 3 : ");
    scanf("%d", &num);
    StackPush(&st, num);
    printf("\n");

    minimumSt = StackMin(st);
    printf("Minimum = %d\n", minimumSt);

    PrintStackElements(&st);
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

//    char Brackets[MAX_SIZE];
//
//
//    printf("Please Enter String : ");
//    scanf("%s", &Brackets);
//    printf("\n");
//
//
//    if(BalancedBrackets(&Brackets))
//        printf("Balanced Brackets :D\n");
//    else
//        printf("Not Balanced Brackets :(\n");



    return 0;
}

int StackMin(STACK st){

    int minimum, i;

    minimum = StackTop(&st);

    for(i = 0; i < 3; i++){
        if(StackTop(&st) <= minimum)
            minimum = StackTop(&st);

        StackPop(&st);
    }


    return minimum;
}

//int BalancedBrackets(char *Brackets){
//    STACK st;
//    int i = 0;
//
//    StackCreate(&st);
//
//    while(Brackets[i] != '\0'){
//        if(Brackets[i] == '{' || Brackets[i] == '[' || Brackets[i] == '(')
//            StackPush(&st, Brackets[i]);
//
//        else {
//            if(!(isEmpty(&st))){
//                if(Brackets[i] == '}'){
//                    if(StackTop(&st) == '{')
//                        StackPop(&st);
//                    else
//                        return 0;
//                }
//
//                if(Brackets[i] == ')'){
//                    if(StackTop(&st) == '(')
//                        StackPop(&st);
//                    else
//                        return 0;
//                }
//
//                if(Brackets[i] == ']'){
//                    if(StackTop(&st) == '[')
//                        StackPop(&st);
//                    else
//                        return 0;
//                }
//
//            }
//            else
//                return 0;
//        }
//
//        i++;
//    }
//
//    if(isEmpty(&st))
//        return 1;
//    else
//        return 0;
//
//}

void StackCreate(STACK *st){
    st->top = -1;
}

void StackPush(STACK *st, int item){
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

int StackTop(STACK *st){
    return st->arr[st->top];
}

void PrintStackElements(STACK *st){
    int top = st->top, i = 1;
    while (top != -1){
        printf("Element number (%d) : %d\n", i, st->arr[top]);
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

//void ReverseString(char *arr, int lenght){
//    STACK st;
//    int i;
//
//    StackCreate(&st);
//
//    for(i = 0; i < lenght; i++)
//        StackPush(&st, arr[i]);
//
//    for(i = 0; i < lenght; i++){
//        arr[i] = StackTop(&st);
//        StackPop(&st);
//    }
//
//}
