#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
}NODE,*PNODE;

typedef struct Stack{
    int i;
    PNODE pTop;
    PNODE pBottom;
}STACK,*PSTACK;

void init(STACK);

int main() {
    STACK stack;
    stack.i = 1000;
    cout<<stack.i<<endl;
    init(stack);
    cout<<stack.i<<endl;

    return 0;
}

void init(STACK pStack){
    pStack.pTop = (PNODE)malloc(sizeof(NODE));
    pStack.i = 10;
}