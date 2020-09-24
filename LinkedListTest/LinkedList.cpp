//
// Created by 冷亚麻色的？ on 2020/2/7.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct somethingveryverylong{
    int num;
    struct node *next;
}Node;

void add(Node *node,int n);
void test(Node);

int learnLink(){

    Node *head = NULL;
    int number;
    Node sth;
    sth.num = 5;
    test(sth);
    cout<<sth.num;
    while (cin>> number){
        add(head,number);
    }
    cout<<"nobody"<<endl;
    return 0;
}

void add(Node *node,int num){
    Node *p = (Node*)malloc(sizeof(Node));
}

void test(struct somethingveryverylong sth){
    sth.num = 10;
}
